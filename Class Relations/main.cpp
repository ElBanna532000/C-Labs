#include <iostream>
#include <graphics.h>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Shape{
    protected:
        int color = WHITE;
    public:
        Shape(int color) : color(color) {}
};



class Line : public Shape
{
private:
    Point start;
    Point end;

public:
    Line() : start(), end(), Shape(WHITE) {}
    Line(int x1, int y1, int x2, int y2, int color = WHITE) : start(x1, y1), end(x2, y2), Shape(color) {} //default color is white.

    void draw()
    {
        setcolor(this->color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
        setcolor(WHITE);
    }
};

class Rectangle : public Shape
{
private:
    Point ul;
    Point lr;
public:
    Rectangle(int color = WHITE) : ul(), lr(), Shape(color) {}
    Rectangle(int x1, int y1, int x2, int y2, int color = WHITE) : ul(x1, y1), lr(x2, y2), Shape(color) {}

    void draw()
    {
        setfillstyle(SOLID_FILL, this->color);
        bar(ul.getX(), ul.getY(), lr.getX(), lr.getY());

    }
};

class Text : public Shape
{
private:
    char *input;
    Point position;
    int textSize;

public:
    Text(char *input, int x, int y, int color = WHITE): Shape(color)
    {
        this->input = input;
        this->textSize = 12;
        this->position = Point(x, y);
    }
    void draw()
    {
        settextstyle(DEFAULT_FONT, 0, this->textSize);
        setcolor(this->color);
        outtextxy(this->position.getX(), this->position.getY(), this->value);
        setcolor(WHITE);
    }

    void setTextSize(int ts){
        this->textSize = ts;
    }
};

class Circle: public Shape
{
private:
    Point center;
    int radius;

public:
    Circle() : center(), radius(0), Shape(WHITE) {}
    Circle(int m, int n, int r, int color = WHITE) : center(m, n), radius(r), Shape(color) {}

    void draw()
    {
        setfillstyle(SOLID_FILL, this->color);
        fillellipse(center.getX(), center.getY(), radius, radius);
        setfillstyle(EMPTY_FILL, WHITE);
    }
};

class Picture
{
private:
    int c, r, l, t;
    Circle *pCircles;
    Rectangle *pRectangles;
    Line *pLines;
    Text *texts;

public:
    Picture() : c(0), r(0), l(0), pCircles(nullptr), pRectangles(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle *pC)
    {
        c = cn;
        pCircles = pC;
    }

    void setRectangles(int rn, Rectangle *pR)
    {
        r = rn;
        pRectangles = pR;
    }

    void setLines(int ln, Line *pL)
    {
        l = ln;
        pLines = pL;
    }

    void setTexts(int tn, Text *pT)
    {
        t = tn;
        this->texts = pT;
    }

    void paint()
    {
        for (int i = 0; i < c; i++)
        {
            pCircles[i].draw();
        }
        for (int i = 0; i < r; i++)
        {
            pRectangles[i].draw();
        }
        for (int i = 0; i < l; i++)
        {
            pLines[i].draw();
        }

        for (int i = 0; i < this->t; i++)
        {
            texts[i].draw();
        }
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Hola");
    int x, y; //cords

    Picture myPic;

    Text text1 = Text("Hello", 30, 120, RED);
    Text text2 = Text("Mahmoud", 30, 180, GREEN);
    text1.setTextSize(3);
    text2.setTextSize(3);

    Circle cArr[3] = {Circle(50, 50, 50, RED), Circle(200, 100, 100, RED), Circle(420, 50, 30, RED)};
    Rectangle rArr[2] = {Rectangle(30, 40, 170, 100, GREEN), Rectangle(420, 50, 500, 300, GREEN)};
    Line lArr[2] = {Line(420, 50, 300, 300, BLUE), Line(40, 500, 500, 400, BLUE)};
    Text tArr[2] = {text1, text2};


    myPic.setCircles(3, cArr);
    myPic.setRectangles(2, rArr);
    myPic.setLines(2, lArr);
    myPic.setTexts(2, tArr);

    myPic.paint();
    getch();

    return 0;
}

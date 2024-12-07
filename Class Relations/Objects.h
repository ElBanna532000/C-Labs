#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

class Shape{
    private:
        int color;

    public:
    Shape(int c);
    int getColor(){return color;}
    int setColor(int val){color=val;}
    ~Shape();

};

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
    Line(int x1, int y1, int x2, int y2, int color = WHITE) : start(x1, y1), end(x2, y2), Shape(color) {}

    void draw()
    {
        setcolor(this->color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
        setcolor(WHITE);
    }
};

class Rect : public Shape
{
private:
    Point ul;
    Point lr;
public:
    Rect(int color = WHITE) : ul(), lr(), Shape(color) {}
    Rect(int x1, int y1, int x2, int y2, int color = WHITE) : ul(x1, y1), lr(x2, y2), Shape(color) {}

    void draw()
    {
        setfillstyle(SOLID_FILL, this->color);
        bar(ul.getX(), ul.getY(), lr.getX(), lr.getY());

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
    int cNum, rNum, lNum, tNum;
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;
    Text *texts;

public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle *pC)
    {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect *pR)
    {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line *pL)
    {
        lNum = ln;
        pLines = pL;
    }

    void setTexts(int tn, Text *pT)
    {
        tNum = tn;
        this->texts = pT;
    }

    void paint()
    {
        for (int i = 0; i < cNum; i++)
        {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++)
        {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++)
        {
            pLines[i].draw();
        }

        for (int i = 0; i < this->tNum; i++)
        {
            texts[i].draw();
        }
    }
};


#endif // OBJECTS_H_INCLUDED

#include <iostream>
#include "Objects.h"
#include <graphics.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Hola");
    int x, y;

    Picture myPic;

    Text t1 = Text("Hello", 30, 120, YELLOW);
    Text t2 = Text("World", 30, 180, CYAN);
    t1.setFontSize(5);
    t2.setFontSize(5);

    Circle cArr[3] = {Circle(50, 50, 50, RED), Circle(200, 100, 100, RED), Circle(420, 50, 30, RED)};
    Rect rArr[2] = {Rect(30, 40, 170, 100, GREEN), Rect(420, 50, 500, 300, GREEN)};
    Line lArr[2] = {Line(420, 50, 300, 300, BLUE), Line(40, 500, 500, 400, BLUE)};
    Text tArr[2] = {t1, t2};


    myPic.setCircles(3, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);
    myPic.setTexts(2, tArr);

    myPic.paint();
    printf("%c\n", getch());

    return 0;
}

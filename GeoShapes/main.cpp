#include <iostream>

using namespace std;

class GeoShape{
    public:
    float dim1;
    float dim2;
    GeoShape(float dim1, float dim2){
        this->dim1 = dim1;
        this->dim2 = dim2;
    }
    virtual float calculateArea() = 0;  //pure virtual function
};

class Rectangle:public GeoShape{

public:
    Rectangle(float dim1, float dim2):GeoShape(dim1, dim2){
        this->dim1 = dim1;
        this->dim2 = dim2;
    }
    float calculateArea(){
        return dim1 * dim2;
    }
};

class Triangle:public GeoShape{
public:
    Triangle(float dim1, float dim2):GeoShape(dim1, dim2){
        this->dim1 = dim1;
        this->dim2 = dim2;
    }
    float calculateArea(){
        return (1/2 * dim1) * dim2;
    }
};

class Square:private Rectangle{

public:
    Square(float dim1, float dim2):Rectangle(dim1, dim2){
        this->dim1 = dim1;
        this->dim2 = dim1;
        }
    float calculateArea(){
        Rectangle::calculateArea();
    }
};

class Circle:private GeoShape{
    public:
    Circle(float dim1):GeoShape(dim1, dim2){
        this->dim1 = dim1;
        this->dim2 = dim1;
    }
    float calculateArea(){
        return 3.14 * dim1*dim1;
    }

};

int main()
{
    //Circle c(2);
    GeoShape* g;
    g=new Rectangle(2,3);
    cout << g->calculateArea()<<endl;
    delete g;

    g=new Triangle(3,4);
    cout << g->calculateArea() << endl;
    delete g;

    g=new Circle(4);
    cout << g->calculateArea() << endl;
    delete g;

    return 0;
}

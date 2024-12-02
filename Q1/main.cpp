#include <iostream>
using namespace std;

class Complex{
    private:
    int real;
    int img;

    public:
    void setReal(int realData){
        real=realData;
    }
    int getReal(){
        return real;
    }

    void setImg(int imgDate){
        img=imgDate;
    }

    int getImg(){
        return img;
    }

    void print() {
        if (real < 0 && img < 0) {
            cout << real << img << "i" << endl;
        } else if (real == 0 && img == 0) {
            cout << "No Data!" << endl;
        } else {
            if (real != 0) {
                cout << real;
            }
            if (img != 0) {
                cout << (img > 0 && real != 0 ? "+" : "") << img << "i";
            }
            //cout << endl;
        }
    }
};

Complex add(Complex a, Complex b){
    Complex result;
    result.setReal(a.getReal()+b.getReal());
    result.setImg(a.getImg()+b.getImg());
    return result;
}

Complex subtract(Complex a, Complex b){
    Complex result;
    result.setReal(a.getReal()-b.getReal());
    result.setImg(a.getImg()-b.getImg());
    return result;
}

int main()
{
    Complex c1, c2, sum, diff;

    c1.setReal(-10);
    c1.setImg(-5);
    c1.print();

    /*c2.setReal(4);
    c2.setImg(7);
    c2.print();


    sum=add(c1,c2);
    sum.print();
    diff=subtract(c1,c2);
    diff.print();*/

    return 0;
}


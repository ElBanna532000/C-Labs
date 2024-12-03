#include <iostream>
using namespace std;

class Complex{
    private:
    int real;
    int img;

    public:
    Complex(){
        real=0;
        img=0;
    }
    ~Complex(){
        cout<<"Complex object has been deleted"<<endl;
    }
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

        if (real == 0 && img == 0) {
            cout << "No Data!" << endl;
        }else {
            if (real != 0) {
                cout << real;
            }
            if (img != 0) {
                cout << (img > 0 && real != 0 ? "+" : "") << img << "i";
            }
        }
    }

    void setComplex(int real, int img){
        this->real=real;
        this->img=img;
    }

    Complex add(Complex c){
        Complex result;
        result.real = this->real + c.real;
        result.img = this->img + c.img;
        return result;
    }

    Complex subtract(Complex c){
        Complex result;
        result.real = this->real - c.real;
        result.img = this->img - c.img;
        return result;
    }
};

/*Complex add(Complex a, Complex b){
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
}*/

int main()
{
    Complex c1, c2, sum, diff;

    c1.setReal(10);
    c1.setImg(5);
    //c1.print();

    c2.setReal(4);
    c2.setImg(3);


    sum = c1.add(c2);
    sum.print();

    diff = c1.subtract(c2);

    diff.print();




    /*c2.setReal(4);
    c2.setImg(7);
    c2.print();

    sum=add(c1,c2);
    sum.print();
    diff=subtract(c1,c2);
    diff.print();*/

    return 0;
}


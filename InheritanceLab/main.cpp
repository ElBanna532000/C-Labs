#include <iostream>

using namespace std;

class Base{
protected:
    int a;
    int b;
public:
Base(int a, int b){
this->a = a;
this->b = b;
cout<<"Base constructor has been called"<<endl;
}

int sum(){
    return a + b;
}

~Base(){
cout<<"Base destructor has been called"<<endl;
}

};

class Derived:public Base{
protected:
    int c;

public:
    Derived(int a, int b, int c):Base(a , b){
        this->c = c;
        cout<<"Derived constructor has been called"<<endl;
    }
    int sum(){
      return Base::sum() + c;
    }

    ~Derived(){
        cout<<"Derived destructor has been called"<<endl;
    }
};

class secDerived:public Derived{
private:
    int d;
public:
    secDerived(int a, int b, int c, int d):Derived(a, b, c){
        this->d = d;
        cout<<"secDerived constructor has been called"<<endl;
    }
    int sum(){
        return Derived::sum() + d;
    }

    ~secDerived(){
        cout<<"secDerived destructor has been called"<<endl;
    }

};

int main()
{
    Base b(5,3); //one constructor and destructor
    Derived d(5,3,8); //base constructor called first, then derived

    int bsum = b.sum();
    cout<<bsum<<endl;

    cout <<endl;
    int dsum = d.sum(); //sum of base is called from within sum of derived.
    cout<<dsum<<endl;

    secDerived s(5,3,8,16); //three constructors have been called.
    int ssum=s.sum();
    cout <<ssum<<endl;
    cout <<endl;

    /*Base * bptr = &d;
    cout<<bptr->sum()<<endl; //Base sum is called
    SecondDerived * sptr = &d; //invalid, because Derived lacks a secDerived object to refer to..
    cout<<sptr->sum()<<endl; //error
    */


    return 0;
}

#include <iostream>
using namespace std;

void swap1(int a, int b){
    int tmp;
    tmp=a;
    a=b;
    b=tmp;

}

void swap2(int *a, int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
    //cout<< "value of a is: "<< *a<< " and value of b is: "<<*b<<endl;

}

void swap3(int &a, int &b){
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
    //cout<< "value of a is: "<< a<< " and value of b is: "<<b<<endl;

}

int main()
{
    int a = 5;
    int b = 3;
    cout<< "value of a is: "<< a<< " and value of b is: "<<b<<endl;
    swap1(a,b);
    cout<< "value of a is: "<< a<< " and value of b is: "<<b<<endl;

    swap2(&a,&b);
    cout<< "value of a is: "<< a<< " and value of b is: "<<b<<endl;

    swap3(a,b);
    cout<< "value of a is: "<< a<< " and value of b is: "<<b<<endl;

    return 0;
}

#include <iostream>

using namespace std;

class List{
    private:
        int top;
        int size;
        int *items;
    public:
        List(){
            //items=nullptr;
            this->size=0;
            top=-1;
            items=nullptr;
        }
        void push(int input){
            if(size==0){
                size++;
                top++;
                items=new int[size];
                items[top]=input;
                return;
            }
            size++;
            top++;
            int *newItems = new int[size]; //allocate new array with new size
            for(int i=0; i<size;i++){
                newItems[i]=items[i];
            }
            newItems[top]=input;
            delete [] items;
            items=newItems;
        }
        int pop(){
            if(size==0)
                return 0;

            int popItem = items[top];
            size--;
            top--;
            int *newItems=new int[size];
            for(int i=0; i<size; i++){
                newItems[i]=items[i];
            }
            delete [] items;
            items=newItems;
            return popItem;
        }

        int getSize(){
            return size;
        }

        void display(){
            for(int i=0; i<size; i++){
                cout <<items[i]<<" ";
            }
            cout<<endl;
        }

        void operator=(List &src){
            if (this == &src) {
                return;
            }

            this->size=src.size;
            this->top=src.top;
            delete [] items;
            items = new int[size];
            for(int i=0; i< size; i++){
                items[i]=src.items[i];
                cout<<items[i]<<endl;
            }
            //return *this;
        }

        ~List(){
            delete [] items;
        }
};

int main()
{
    List l1;
    l1.display();
    cout<<l1.getSize()<<endl;

    l1.push(5);
    l1.display();
    cout<<l1.getSize()<<endl;

    l1.push(7);
    l1.display();
    cout<<l1.getSize()<<endl;

    l1.push(9);
    l1.display();
    cout<<l1.getSize()<<endl;

    /*cout <<l1.pop()<<endl;
    l1.display();
    cout<<l1.getSize()<<endl;

    cout <<l1.pop()<<endl;
    l1.display();
    cout<<l1.getSize()<<endl;*/

    l1.push(11);
    l1.display();
    cout<<l1.getSize()<<endl;

    List l2;
    l2=l1;
    l2.display();
    cout<<l2.getSize()<<endl;




    return 0;
}

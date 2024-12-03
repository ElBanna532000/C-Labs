#include <iostream>
#include <chrono>
#include <thread>
#include "conio.h"
#define UP 65
#define DOWN 66
#define ESC 27
#define ENTER 10
#define HOME 72
#define SIZE 50

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;


typedef struct Employee {
    int id;
    string name;
    int salary;
} Employee;

class Stack{
    private:
        int top;
        int size;
        Employee *employees;

    public:
        static int counter;
        Stack(int size){
            this->size=size;
            top=-1;
            employees=new Employee[size];
            cout << "A Stack of size "<<size<<" has been created"<<endl;
        }
        ~Stack(){
            delete[] employees;
            cout<<"Stack has been deleted"<<endl;

        }
        int push(){
            if(top == size-1){
                return 0;
            }
            else{
                top++;

                cout<<"Enter employee id: ";
                cin>>employees[top].id; //add the employee id, top is the index of array

                cout<<"Enter employee Name: ";
                cin>>employees[top].name;

                cout<<"Enter employee Salary: ";
                cin>>employees[top].salary;
                cin.ignore();

                counter++;
                return 1;
            }
        }
        int pop(){
            if(top == -1){
                return 0;
            }else{
                top--;
                counter--;
                return 1;
            }
        }
        void print(){
            if(top==-1){
                cout<<"Stack is empty, No Employees to show!"<<endl;
            }
            else{
                printf("Displaying all Employees\n");
                printf("================================================\n");
                for(int i=0; i<counter; i++){
                    cout<<"ID: "<<employees[i].id<<", Name: "<<employees[i].name<<", Salary:"<<employees[i].salary<<endl;
                    cout<<"___________________________________________________________"<<endl;
                }
            }
        }
};

int Stack::counter = 0;

void show_menu(int cursor) {
    system("clear"); // Clear the terminal
    textcolor(BLACK); // Set default color to black.
    for (int i = 0; i < 3; i++) {
        if (i == cursor) {
            textcolor(RED); // Highlight selected option in red.
        }

        switch(i) {
            case 0:
                printf("PUSH\n");
                break;
            case 1:
                printf("POP\n");
                break;
            case 2:
                printf("PRINT_STACK\n");
                break;
        }
        textcolor(BLACK);   // Reset color to Black after printing each option.
    }
}


int main() {
    int cursor = 0;  // Initialize cursor position
    char realkey=0;
    int isRunning = 1;  // Flag to keep the menu running
    int size;
    cout<<"Enter size of the Stack: ";
    cin>>size;
    cin.ignore();

    Stack s(size);

    sleep_for(3s);

    show_menu(cursor);  // Display the initial menu
    while (isRunning) {
        char firstkey = 0;
        firstkey = getch();  // Get user input

        if(firstkey==ENTER){    //first Key condition for the ENTER btn
            system("clear");

            if(cursor==0){
                if(s.push())
                    cout<<"Employee added successfully!"<<endl;
                else
                    cout<<"Size is full, cannot add a new employee"<<endl;

                sleep_for(3s);
                show_menu(cursor);
            }

            else if(cursor==1){
                if(s.pop()){
                    cout << "Employee has been removed successfully!"<<endl;

                }
                else
                    cout<< "Stack is Empty, No employee to be removed!"<<endl;

                sleep_for(5s);
                system("clear");
                s.print();
                sleep_for(5s);
                system("clear");
                show_menu(cursor);
            }
            else if(cursor==2){
                s.print();
                sleep_for(5s);
                show_menu(cursor);
            }
            else{
                isRunning=0;
            }
        }

        if (firstkey == 27) {
            getch();
            realkey=getch();

            if (realkey == UP) {  // Move cursor up
                cursor = (cursor == 0) ? 2 : cursor - 1;  // Wrap to last option if at top ---
                show_menu(cursor);
            } else if (realkey == DOWN) {  // Move cursor down
                cursor = (cursor == 2) ? 0 : cursor + 1;  // Wrap to first option if at bottom
                show_menu(cursor);
            }
            else if(realkey==HOME){
                cursor=0;
                show_menu(cursor);
            }
        }
    }
    textcolor(BLACK);   // Reset color to default
    return 0;
    }


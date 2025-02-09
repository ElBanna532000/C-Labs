#include <iostream>

#define TERM '\0'


using namespace std;


int strLength(char *str){
    int i=0;
    while(str[i]!=TERM){
        i++;
    }
    return i;
}


class String{           //array of characters - asks user for the size of the string
    private:            //asks the user to input the string he wants
        char *str;
        int size;

    public:
        //Parameterized Constructor
        String(char *text){
            this->size=strLength(text);
            //cout<<size;
            str = new char[size];
            for(int i=0; i<size; i++){
                str[i]=text[i];
            }
        }
        //String Length
        int strSize(){
            int i=0;
            while(this->str[i]!=TERM){
                i++;
            }
            return i;
        }

        void reSize(int newSize, char c=' '){        //str1-> 5 -----> 9

            char* newArray=new char[newSize]; //new pointer points to new array with the new size
            if(this->size < newSize){
                //if new size bigger than current size
                for(int i=0; i < this->size; i++){
                    newArray[i]=this->str[i];
                }
                for(int i=this->size; i<newSize; i++){
                    newArray[i]=c;
                }
                newArray[newSize]=TERM;
                //return *this;
            }
            else{       //new size < current size
                for(int i=0; i<newSize;i++){
                    newArray[i]=this->str[i];
                }
                newArray[newSize]=TERM;
            }
            delete [] this->str;
            this->str=newArray;
            //return *this;
        }

        void operator+=(const String &str2){

            int sizeNew=this->size+str2.size;
            char *strNew=new char[sizeNew+1];

            for(int i=0; i<this->size; i++){
                strNew[i]=this->str[i];
            }
            int j=0;
            for(int i=this->size; i<sizeNew; i++){
                strNew[i]=str2.str[j];
                j++;
            }
            strNew[sizeNew]=TERM;       //place the terminator at the end of the string
            delete[] this->str;         //delete the old array allocation
            this->str=strNew;           //assign the THIS pointer to points to the new array
            this->size=sizeNew;         //assign the THIS size to the new size
            //return *this;
        }

        bool operator<=(const String &str2){
                if(this->size > str2.size)
                    return false;
                else
                    return true;
        }

        bool operator<(const String &str2){
                if(this->size > str2.size)
                    return false;
                else
                    return true;
        }

        bool operator>=(const String &str2){
                if(this->size < str2.size)
                    return false;
                else
                    return true;
        }

        bool operator>(const String &str2){
                if(this->size < str2.size)
                    return false;
                else
                    return true;
        }

        void display(){
            if(this->str)
                cout << this->str<<endl;
            else
                cout <<"Empty String"<<endl;
        }



        ~String(){
            delete[] this->str;
        }
};

int main()
{
    char message1 []="MaHmOuD";
    char message2 []="Mohamed";

    String s1(message1);
    String s2(message2);
    s1.display();
    //String s3;
    s1+=s2;
    s1.display();
    s2.display();

    if(s1<=s2)
        cout<<"s1 is smaller than or equal to s2"<<endl;
    else
        cout<<"s1 is bigger than s2"<<endl;

    s2.reSize(4);
    s2.display();


    /*cout <<"Size of the array is "<< s1.strSize() << endl;
    cout <<"Lower case of the array is: "<< s1.strToLower() << endl;
    cout <<"Lower case of the array is: "<< s1.strToUpper() << endl;
    cout <<"Copied String is: "<<s3.getStr() << endl;*/

    return 0;
}

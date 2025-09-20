#include <iostream>
using namespace std;

class complex {
    int a, b;
public:
    complex(){
        cout<<"default constructor"<<endl;
    }
    complex(int x, int y) {
        cout<<"normal constructor"<<endl;
        a = x;
        b = y;
    }
    void set(int x, int y) {
        cout<<"set method called"<<endl;
        a = x;
        b = y;
    }
    void get() {
        cout<<"real part : "<<a<<endl;
        cout<<"imaginary part : "<<b<<endl;
    }
};

int main() {
    complex c;//default constructor called
    c = complex(6, 7);//normal constructor called

    complex* ptr = new complex;//same as above and default constructor called
    complex* ptr1 = new complex(100, 200);//normal constructor called
    (*ptr).set(10, 20);//method called

    ptr->get();
    ptr1->get(); 

    complex* ptr2 = new complex[3];//array of complex class objects and default constructor called 3 times
    ptr2->set(5, 10);//method called
    (*(ptr2 + 1)).set(15, 20);//method called
    *(ptr2 + 2) = complex(25, 30);//CAN'T USE ARROW OPERATOR as not a method 
}
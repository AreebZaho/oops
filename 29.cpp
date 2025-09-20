#include <iostream>
using namespace std;

class complex {
    int a, b;
public:
    complex();//Constructor is automatically invoked when when object of class is created, constructor doesn't have any return type, garbage value set if values not defined in func,
    //must be declared in public, when obj created and constructor called all code in it runs (prints too), can pass default args, cannot refer to it's address;
    void get() {
        cout<<a<<" + i"<<b<<endl;
    }
};

complex::complex() {//default constructor as doesn't accept any values (not even void)
    a = 0;//initialising with 0 in default constructor so compiler doesn't put garbage value in it if we use .get() with obj
    b = 0;
    cout<<"Obj created and constructor automatically invoked so this line of code in it getting executed too"<<endl;
}

int main() {
    complex x;
    x.get();
}
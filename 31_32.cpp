#include <iostream>
using namespace std;

class complex {
    int a, b;
public:
    // complex(int x, int y) {//parameterised constructor
    //     a = x, b = y;
    // }
    // complex(int x) {//only 1 parameter passed and other value made 0 when constructor invoked
    //     a = x, b = 0;                
    // }
    complex() {//default constructor
        a = 0, b = 0;
    }
    complex(int x, int y = 10) {//constructor with defualt arguments means if value is pased, converts to that or uses the default case
        a = x, b = y;//must not define 2 arg/1 arg constructor if defining this - this is a single func for both of them, like 2 in 1 (just make x = 0, y = 0 in arg segment) 
    }
    void get() {
        cout<<"a = "<<a<<", b = "<<b<<endl;
    }
};

int main() {
    complex c1(1, 2);
    complex c2(4);
    complex c3;
    c1.get(), c2.get(), c3.get();

}
#include <iostream>
using namespace std;

class complex {
    int a;//both independent dimentions of class
    int b;
public:
    void set(int x, int y) {
        a = x;
        b = y;
    }
    void get() {
        cout<<a<<" + i"<<b<<endl;
    }
    void setbysum(complex c1, complex c2) {//passing class' objects in func
        a = c1.a + c2.a;
        b = c1.b + c2.b;
    }
};

// void setbysum(complex c1, complex c2) { //defining this func outside of class gives error as a, b are private and can't be accessed 
//         a = c1.a + c2.a;
//         b = c1.b + c2.b;
//     }

int main() {
    complex c1, c2, c3;
    c1.set(1, 2);
    c2.set(-1, 3);
    c3.setbysum(c1, c2);
    c3.get();
    
}
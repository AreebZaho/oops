#include <iostream>
using namespace std;

class test {//initialization list in constructors
    int a, b;
public:
    // test(int x, int y) : a(x), b(a) {//correct as a declared first and value assigned first to it
    // test(int x, int y) : a(b), b(a) {//a declared first but receives garbage value as b undeclared then that garbage value is passed to b() via putting (a) in it
    test(int x, int y) : b(x), a(b) {//gives garbage value as a declared first in class and a() called first which assigns garbage value to it then assign value to b like above
    // test(int x, int y) : b(a + y), a(x) {//works 
        cout<<"test constructor called"<<endl;
        cout<<"a : "<<a<<endl;
        cout<<"b : "<<b<<endl;
    }
};

int main() {
    test t(1, 2);

}
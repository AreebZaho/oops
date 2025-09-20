#include <iostream>
using namespace std;

class Y;

class X {
    int data;
    friend void add(X, Y);//only use direct class names (X,Y) if done forward declaration of Y for compiler, otherwise use (class X/Y)
public:
    void set(int val) {
        data = val;
    }
    void get() {
        cout<<"Data: "<<data<<endl;
    }
};

class Y {
    int num;
    friend void add(class X, class Y);
public:
    void set(int val) {
        num = val;
    }
};

void add(X o1, class Y o2) {//mention class or not in external func for classes but it's own data type made 
    cout<<"Sum of data of X and Y = "<<(o1.data + o2.num);
}

int main() {
    X a;
    a.set(5);
    Y b;
    b.set(6);
    add(a, b);
}
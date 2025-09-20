#include <iostream>
using namespace std;

class base1 {
public:
    void name() {
        cout<<"Stanley"<<endl;
    }
};

class base2 {
public:
    void name() {
        cout<<"Stanford"<<endl;
    }
};

class derived : protected base1, protected base2 {
public:
    void b1name() {//derived class has a func name() but of which parent class 
        base1 :: name();//to clear ambiguity of which parent class' func will be used 
    }
    void b2name() {//can also make multiple methods in derived class to tell which method uses which parent class' name() func
        base2 :: name();
    }
    void name() {//can have same func as parent too, overrides parent class' name() during run time 
        cout<<"derived's name"<<endl;
    }
};

class B {
public:
    void say() {
        cout<<"Bill"<<endl;
    }
};

class D : public B {
public:
    void say() {//although B's say() func present but is "overriden" by D's original say() func
        cout<<"Gravity Falls"<<endl;
    }//if D doesn't have a func named say() and if say() called as method of D then B's say() printed only
};

int main() {
    base1 b1;
    base2 b2;
    derived d;
    b1.name();
    b2.name();
    d.b1name(); d.b2name();
    B B;
    D D;
    B.say();
    D.say();//won't be printed if D's say() is protected/private and inherited say() of B is public as compiler overrides others by D's original say() func when called
}
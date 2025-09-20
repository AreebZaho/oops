#include <iostream>
using namespace std;

class base {
public:
    int var_base;
    void get() {
        cout<<"value of var_base : "<<var_base<<endl;
    }
};

class derived : public base {
public:
    int var_derived;
    void get() {
        cout<<"value of var_base : "<<var_base<<endl;
        cout<<"value of var_derived : "<<var_derived<<endl;
    }
    void test() {
        cout<<"test successful"<<endl;
    }
};

int main() {//RUN TIME POLYMORPHISM or LATE BINDING 
    base *basePtr = new base();
    derived *dptr = new derived();
    derived derivedObj;
    base baseObj;
    basePtr = &derivedObj;//although base class' pointer pointed to derived class but behaves as base class' pointer only
    
    // dptr = &baseObj;//invalid, can't assign derived class pointer to base class obj

    // basePtr->var_derived;//invalid property of base pointer can't be accessed
    basePtr->var_base = 3;
    basePtr->get();//calls get of base class only
    // basePtr->test();//invalid as abse class' pointer doesn't know method of derived class

    derived *dptr2 = new derived();
    dptr2 = &derivedObj;//has acess to all of derived's prop/methods

    dptr2->var_base = 1;
    dptr2->var_derived = 2;
    dptr2->get();//derived's method that prints var value of both base, derived class
    dptr2->test();

}
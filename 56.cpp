#include <iostream>
using namespace std;

class base {
public:
    int var_base = 1;
    virtual void get() {//virtual means if base's pointer pointing to derived's obj then run derived's methods only and not base's [run time polymorphism]
        cout<<"value of var_base via base's get() func : "<<var_base<<endl;
    }
};

class derived : public base {
public:
    int var_derived = 2;
    void get() {
        cout<<"value of var_base via derived's get() func: "<<var_base<<endl;
        cout<<"value of var_derived via derived's get() func : "<<var_derived<<endl;
    }
    void test() {
        cout<<"test successful"<<endl;
    }
};

int main() {
    base baseObj;
    derived derivedObj;
    base* basePtr;
    derived* derivedPtr;

    basePtr = &derivedObj;
    basePtr->get();//
}
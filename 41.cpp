#include <iostream>
using namespace std;

class base1 {
protected:
    int base1int;
public:
    void set_base1(int a) {
        base1int = a;
    }
};
//making member protected so can be directly used in derived and don't have to use func to perform action on it
class base2 {
protected:
    int base2int;
public:
    void set_base2(int a) {
        base2int = a;
    }
};

class derived : public base1, public base2 {
    //protected contains base1int, base2int
public://contains set() func of both base classes
    void get() {
        cout<<"Value of base1 object : "<<base1int<<endl;
        cout<<"Value of base2 object : "<<base2int<<endl;
        cout<<"Value of derived object : "<<base1int + base2int<<endl;
    }
};

int main() {
    base1 b1;
    base2 b2;//can't be same or conflicting declaration error
    b1.set_base1(5);
    b2.set_base2(10);//setting these for base1,2 have no relevance in derived's object, should use these methods with derived's obj.(method);
    derived d;
    d.get();//has garbage values for base1,2int even though they were set earlier but in their respective classes and not their derived class
    d.set_base1(5);//so need to set them for object of derived class 
    d.set_base2(10);
    d.get();
}
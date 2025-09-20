#include <iostream>
using namespace std;

class base {
    int data1;//not inheritable
public:
    int data2;
    int set(int x, int y) {
        data1 = x;
        data2 = y;
    }
    int get_data1() {//(inheritable) method to obtain data1 outside of base class
        return data1;
    }
};

class derived : private base {//data2, set(), get_data1(), get_data2() derived in private part now
    int data3;//contains set(), get_data1(), get_data2() also
public:
    int process() {//can use private methods of derived in this public method of derived
        set(10, 20);//part of private now and can't be directly used in main so using VIA process : makes data1 = 10, data2 = 20
        data3 = data2 * get_data1();//data1 not derived directly but by set() and can only be accessed by get_data1()
    }
    void display() {
        cout<<"Data 1: "<<get_data1()<<", Data 2: "<<data2<<", Data 3 = "<<data3<<endl;//can use data 2,3,get_data1() directly as part of derived func now, but not data1 directly
    }
};

int main() {
    derived d;
    // d.set(10, 20);//cannot use as private method of derived class
    d.process();
    d.display();
}
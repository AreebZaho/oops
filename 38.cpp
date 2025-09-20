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

class derived : public base {//can use data2 directly as derived to public and data1 can be accessed only by get_data1() is it's derived to public and no the data1 value directly
    int data3;
public://contains set(), get_data1(), get_data2() also
    int process() {
        data3 = data2 * get_data1();//data1 secretly present in this class with help of of set() and get_data1()??
    }
    void display() {
        cout<<"Data 1: "<<get_data1()<<", Data 2: "<<data2<<", Data 3 = "<<data3<<endl;//can use data 2,3,get_data1() directly as part of derived func now, but not data1 directly
    }
};

int main() {
    derived d;
    d.set(10, 20);
    d.process();
    d.display();
}

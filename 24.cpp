#include <iostream>
using namespace std;

class employee {
    int id;
public:
    static int count;//static member of 'class' and can update each time a class' object is defined (outside class, defalut value = 0) [PROPERTY OF CLASS]
    void set(int ID) {
        id = ID;
        count++;
    }
    void get() {
        cout<<"id "<<id<<" and employee no. "<<count<<endl;
    }
    void getCount() {
        cout<<"count = "<<count<<endl;
    }
};

int employee::count;//static initialises from 0 by defualt but we can initialise it (HERE) to any no. and begin count from that 

int main() {
    employee a;
    a.set(721);//if i only define a object and not set() it (count++ in it only) then it's not counted, the count will increment for objects which are set() (has count++)
    a.get();
    a.getCount();//correct way to write a class' static funcs
    cout<<employee::count;//print static properties of class this way 
    //getCount() requires class' object 
    employee b;
    b.set(812);
    b.get();
    b.getCount();
    employee c;
    c.set(918);
    c.get();
    c.getCount();//displays the count at it's 'current' moment
    // b.get();//if i try to print b with it's count, it will display the 'current count' and not the one made when b was set();
    
}//at the end, count is just there to keep track of how many objects were defined and not like index of any object
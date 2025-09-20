#include <iostream>
using namespace std;

class number {
private:
public:
    int a, b;
    number(){
        cout<<"Default constructor invoked"<<endl;
        a = 0, b = 0;
    }

    number(int _a, int _b) {
        cout << "parameterised constructor called"<<endl;
        a = _a;
        b = _b;
    }
    //*WHEN COPY CONSTRUCTOR NOT PRESENT, COMPILER SUPPLIES IT'S OWN COPY CONSTRUCTOR AND THE CODE IN MAIN STILL WORKS ABSOLUTELY FINE JUST THAT 'COPY CONSTRUCTOR NOT INVOKED'
    number(number &obj) {//*copy constructor
        cout<<"Copy Constructor Invoked"<<endl;
        this->a = obj.a;
        this->b = obj.b;
    }

    void get() {
        cout<<"a = "<<a<<", b = "<<b<<endl;
    }
};

int main() {//* 4 CASES:
    number n1(5, 6);
    //* number n2 = number(anything);//*can't use this if copy constructor is present
    number n2(n1);//*creates new object + copy constructor invoked
    n2.get();
    number n3;
    n3 = n2;//*creates new object + copy constructror not called as directly assigned
    n3.get();
    number n4 = n3;//*creates new object + copy constructor invoked as declaring obj and assigning it here also
    n4.get();//*even if removing copy constructor, above statement still works fine but 'copy constructor invoked missing'
    //*NOTE: IF ASSIGNING INTEGRAL VALUES INSTEAD OF OBJECTS (x, y) THEN COPY CONSTRUCTOR NOT INVOKED
}
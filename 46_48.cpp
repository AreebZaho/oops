#include <iostream>
using namespace std;

class base1
{
protected:
    int data1;

public:
    base1() { cout << "base1 default constructor" << endl; };
    base1(int i)
    {
        data1 = i;
        cout << "constructor called for base1" << endl;
    }
    void get()
    {
        cout << "data1 : " << data1 << endl;
    }
};

class base2
{
protected:
    int data2;

public:
    base2() { cout << "base2 default constructor" << endl; };
    base2(int i)
    {
        data2 = i;
        cout << "constructor called for base2" << endl;
    }
    void get()
    {
        cout << "data2 : " << data2 << endl;
    }
};

class derived : public base1, public base2
{          // first constructor of base1 called then base2 [if assigning values to both using derived's constructor]
protected: // contains data1,2 also
    int derived1, derived2;

public:                                                          // contains base constructors, get() funcs
    derived() { cout << "derived default constructor" << endl; } // prints statement of default constructor of base1,2 in order they they are inherited

    derived(int a, int b, int c, int d) : base2(b), base1(a)
    { // order of mentioning doesn't matter, base constr will be called whose is inherited first (to the left)
        // data1 = a, data2 = b;//could have done this also but then constructors of base 1,2 won't be called
        cout << "derived class' 4 parameter constructor called" << endl;
        cout << "assigned values to data1,2 using base1,2 constructors" << endl;
        derived1 = c;
        derived2 = d;
    }

    derived(int x) : base1(x)
    { // calls constructor of both parent classes but base1's (int) constructor first THEN base2's defualt constructor (inheritance order)
        cout << "derived class' 1 parameter constructor that assigned value to base1's data1" << endl;
    }

    derived(int y, float k) : base2(y)
    { // calls constructor of both parent classes but base1's default constructor first THEN base2's (int) constructor (inheritance order)
        cout << "derived class' 1 parameter constructor that assigned value to base2's data2" << endl;
    } // float k only exists so constructor overloading happpens otherwise above constructor and this identical

    // derived(int x, int y) : base1(x), base2(y) {}//can't exist because of below constructor cuz overloading (2 conditions : num of args / arg data types)

    derived(int n, int m)
    { // calls base class default consructors
        cout << "derived class' 2 parameter constructor" << endl;
        derived1 = n;
        derived2 = m;
    }

    void get()
    {
        base1 ::get();
        base2 ::get();
        cout << "derived1 : " << derived1 << endl;
        cout << "derived2 : " << derived2 << endl;
    }
};

int main()
{              // WHENEVER DERIVED ONJECT MADE, BOTH BASE1,2 CONSTRUCTOR CALLED IN ORDER OF INHERITANCE (BASE1 -> BASE2) WHICHEVER CONSTRUCTOR DEPENDING ON USE CASE
    derived d; // c++ can make defualt constructor too
    cout << endl;
    derived d1(100);
    cout << endl;
    derived d2(200, 0.5f);
    cout << endl;
    derived d3(10, 20);
    d3.get(); // has garbage values for data1,2 values here
    cout << endl;
    derived d4(1, 2, 3, 4); // 4 value contructors called : base1 -> base2 -> derived
    d4.get();               // assigns : data1 -> data2 -> derived1 -> derived2
}
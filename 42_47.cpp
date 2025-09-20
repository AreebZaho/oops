#include <iostream>
#include <cmath>
using namespace std;

class simple_calculator {
protected:
    int a;
    int b;
    int add, sub, multiply, div;
public:
    void set(int n1, int n2) {
        a = n1;
        b = n2;
    }
    void process() {
        add = a + b;
        sub = a - b;
        multiply = a * b;
        div = a / b;
    }
    void get() {
        cout<<"Sum : "<<add<<endl;
        cout<<"Difference : "<<sub<<endl;
        cout<<"Product : "<<multiply<<endl;
        cout<<"Quotient : "<<div<<endl;
    }
};

class scientific_calculator {
protected:
    int c;
    int d;
    double exp, sq, sq_root, cube_root;
public:
    void set(int n1, int n2) {
        c = n1;
        d = n2;
    }
    void process() {
        exp = pow(c, d);//other 3 performed only on c
        sq = c * c;
        sq_root = sqrt(c);
        cube_root = cbrt(c);
    }
    void get() {
        cout<<"Power : "<<exp<<endl;
        cout<<"Square : "<<sq<<endl;
        cout<<"Square root : "<<sq_root<<endl;
        cout<<"Cube root : "<<cube_root<<endl;
    }
};

class hybrid_calculator : public simple_calculator, public scientific_calculator {
public:
    void set(int x1, int x2) {//even though both set1,2() are public, to set for both the simple and scientific calculator directly for once, using this function
        simple_calculator :: set(x1, x2);//CAN USE SCOPE RESOLUTION TO TELL WHICH SET?GET IS OF WHICH CLASS WHILE IN MULTIPLE INHERITANCE 
        scientific_calculator :: set(x1, x2);
    }
    void process() {//same reason as above, instead of calling both 1,2 in main, doing this in hybrid_calc to use for once
        simple_calculator :: process();
        scientific_calculator :: process();
    }
    void get() {
        simple_calculator :: get();
        scientific_calculator :: get();
    }
    //can also write all the above the stuff in one single master_function with 2 args taking x1, x2 and doing all the stuff within itself only
};

int main() {
    int x1, x2;
    cout<<"Enter 1st num then 2nd num : "<<endl;
    cin>>x1>>x2;

    hybrid_calculator z;
    z.set(100,3);
    z.process();//few of the scientific_calc funcs performed only on 'a'
    z.get();
}
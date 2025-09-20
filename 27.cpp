#include <iostream>
using namespace std;

// class calculator;
// //even if giving definition of func here, doesnt matter beacuse will have to define in end with a,b (so after complex) and complex includes calc::func, must define calculator
// class complex {                                                                                                      //above it with defition of the func
//     int a, b;
//     friend int calculator::realSumComplex(complex o1, complex o2);//DOESN'T WORK AS CALCULATOR'S FUNC UNKNOWN IF IT'S IN IT OR NOT, SO IF WANTING TO DEFINE CALCULATOR
// public://ABOVE, WILL NOT BE ABLE TO USE THE FUNC INSIDE CALC MEANS WILL HAVE TO GIVE DEFINITION ONLY AND ON 3RD POSITION COMES
//     void set(int n1, int n2) {//COMPLEX AND IN THE END THE FUNCTION WITH A, B KNOWN..MEANS THE BELOW CORRECT METHOD ONLY WITH DEFINING COMPLEX AT TOP
//         a = n1, b = n2;
//     }
//     void get() {
//         cout<<a<<" + "<<b<<"i"<<endl;
//     }
// };

// class calculator {
// public: 
//     int add(int a, int b) {
//         return a+b;
//     }
//     int calculator::realSumComplex(complex o1, complex o2) {
//         return (o1.a + o2.a);
//     }
// };

// TESTING ABOVE:::::::::

class complex;//defined above so func in calculator can recognise [FORWARD DECLARATION]
     
class calculator {//can't be put at top as refrence to complex won't be there for compiler which is being used by a func of this class
public: 
    int add(int a, int b) {
        return a+b;
    }
    int realSumComplex(complex, complex);//can't write full func as compiler won't be able to detect a,b (private data members of complex) so GIVING DEFINITION OF FUNC
    int compSumComplex(complex, complex);
};

class complex {//class containing friend always defined below 
    int a, b;
    friend int calculator::realSumComplex(complex, complex);//can't be put at the top as has refrence to a friend class' func 
    friend int calculator::compSumComplex(complex, complex);
    //or can make entire "friend class calculator" instead of a few func of it
public:
    void set(int n1, int n2) {
        a = n1, b = n2;
    }
    void get() {
        cout<<a<<" + "<<b<<"i"<<endl;
    }
};

int calculator::realSumComplex(complex o1, complex o2) {//now calc, complex classes defined and a,b are known
        return (o1.a + o2.a);
    }
int calculator::compSumComplex(complex o1, complex o2) {//now calc, complex classes defined and a,b are known
        return (o1.b + o2.b);
    }

int main() {
    complex c1, c2;
    c1.set(1, 4);
    c2.set(2, 5);
    calculator calc;
    cout<<"sum of real parts: "<<calc.realSumComplex(c1, c2)<<endl;
    cout<<"sum of complex parts: "<<calc.compSumComplex(c1, c2)<<endl;
}

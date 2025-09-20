#include <iostream>
using namespace std;

//                             Private inheritance:        Protected inheritance:      Public inheritance:
// Private members             Not Inherited               Not Inherited               Not Inherited
// Protected members           Private                     protected                   protected
// Public members              private                     protected                   public

class base {
    int a;
protected://like private but inheritable (inheritable by other classes but not accessible in the public scope)
    int b;
public:
    void get() {
        cout<<b<<endl;
    }
};

class derived : protected base {

};

int main() {
    base b;
    derived d;
    // d.get();//not accessible as get() is public for base but derived into protected for derived
    b.get();//[MEANS WE CAN USE GET() IN MAIN WITH BASE CLASS' OBJECT AND NOT OF DERIVED'S OBJECT]
}
#include <iostream>
using namespace std;

int count = 0;//global variable, can also declare static 

class num {
public:
    num() {//default constrctor invoked as soon as object created
        count++;
        cout<<"Constructor called for obj number: "<<count<<endl;
    }

    ~num() {//destructor for when object destroyed
        cout<<"Destructor called here and count is: "<<count<<endl;
        count--;
        cout<<"Total objects left now: "<<count<<endl;
    }
};

int main() {
    cout<<"entered main......"<<endl;
    cout<<"creating n1"<<endl;
    num n1;
    cout<<"creating n2"<<endl;
    num n2;
    {
        cout<<"ENTER BLOCK.........."<<endl;
        num n3;//created in block and will be destroyed in block too
        cout<<"EXIT BLOCK........"<<endl;
    }//destructor for n3 called here, block objects destroyed after it ends and MAIN BLOCK ELEMENTS DESTROYED WHEN MAIN ENDS
    cout<<"creating n4"<<endl;
    num n4;
    cout<<"main program ends......."<<endl;
}//after main ends, destructors called AND COUNT IS ONLY A TRACK OF HOW MANY ARE CREATED WHICH THEN 1 BY 1 DESTROYED
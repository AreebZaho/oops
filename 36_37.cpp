#include <iostream>
using namespace std;

class employee {
public:
    int id;
    int salary;
    employee(){}//default constructor necessary to be made for parent class 
    employee(int ID) {//1 arg constructor
        id = ID;
        salary = 34;
    }
    void test() {
        cout<<111111;
    }
};

class programmer : public employee {//(visibility-mode) - default private, means public methods of parent class copied to private methods of child class, PRIVATE OF BASE NEVER INHERITED
    // int id ;        //if inherited as public, then (PUBLIC ONLY) methods and members inherited to public section of derived class 
    // int salary;     //and if inherited as public, means they go directly into public section and can use them in main() also directly (with .) as they are public
public:
    int language = 7;
    programmer(int ID) {//THINKS ABOUT CALLING AND USING EMPLOYEE'S CONSRUCTOR AS DERIVED CLASS OF IT, SO MAKING A DEFAULT CONSTRUCTOR FOR EMPLOYEE 
        id = ID;//id is private data member of emloyee and hence, not inherited
        salary = 35;
    }
    void get() {
        cout<<"ID: "<<id<<", Salary: "<<salary<<", Lanuage: "<<language<<endl;
    }
};

int main() {
    employee e1(5), e2(7);//no error as constructor exists for employee class
    programmer p(1);
    cout<<p.language<<endl;
    p.get();
    p.test();//arbitrary method, is public of employee, inherited into programmer, if inherited as PRIVATE-can't be used in main, if as PUBLIC - can be used in main
}
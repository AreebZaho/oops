#include <iostream>
using namespace std;

class Tesla {//abstract class is a class that is made only to be inherited to other classes and give it's abstract methods to them 
protected:
    int wheels;
    string name;
public:
    Tesla(int wheels, string name) {
        this->wheels = wheels;
        this->name = name;
    }
    virtual void get() = 0;//pure virtual func (must be implemented in derived classes and can't be implemented here) 
};

class ModelX : public Tesla {
protected:
    float carRating;
public:
    ModelX(int wheels, string name, float carRating) : Tesla(wheels, name) {
        this->carRating = carRating;
    }
    void get() {//implementation of pure virtual func
        cout<<name<<endl;
        cout<<"Wheels : "<<wheels<<endl;
        cout<<"Rating: "<<carRating<<endl;
    }
};

class Cybertruck : public Tesla {
protected:
    float truckRating;
public:
    Cybertruck(int wheels, string name, float truckRating) : Tesla(wheels, name) {
        this->truckRating = truckRating;
    }
    void get() {//implementation of pure virtual func
        cout<<name<<endl;
        cout<<"Wheels : "<<wheels<<endl;
        cout<<"Rating: "<<truckRating<<endl;
    }
};

int main() {
    ModelX i(4, "ModelX 4480", 4.6);
    Tesla *ptr = &i;

    Cybertruck j(6, "Cybertruck 6690", 4.2);
    Tesla *ptr1 = &j;

    ptr->get();
    cout<<endl;
    ptr1->get();
}

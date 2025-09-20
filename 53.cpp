#include <iostream>
using namespace std;

class test {
    int a;
public:
    void set(int a) {
        this->a = a;//this = pointer
    }
    test set1(int a) {
        this->a = a;
        return *this;//returns obj of class 
    }
    test* set2(int a) {
        this->a = a;
        return this;//returns pointer pointing to obj which needs to be dereferenced
    }
    void get() {
        cout<<"value of a : "<<a<<endl;//can use this-> also
    }
};

int main() {
    test t, t1, t2, t3;
    t.set(0);
    t.get();

    t1.set1(1);//returns obj whose properties/methods can be used
    t1.get();

    t2.set1(2).get();
    // cout << t2.set1(2) also possible if 'a' wasn't private

    (*(t3.set2(5))).get();//or
    (t3.set2(5))->get();
}
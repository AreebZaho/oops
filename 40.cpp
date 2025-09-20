#include <iostream>
using namespace std;

class student {
protected:
    int roll_num;
public:
    void set1(int n) {
        roll_num = n;
    }
    void get1() {
        cout<<"roll num is: "<<roll_num<<endl;
    }
};

class exam : public student {
protected:
    float math;
    float physics;
public:
    void set2(float m, float p) {
        math = m;
        physics = p;
    }
    void get2() {
        cout<<"marks in math: "<<math<<", phy: "<<physics<<endl;
    }
};

class result : public exam {
protected://math, physics, roll_num also present in protected
    float score;
public://set() and get() methods for roll_num, physics, math also present in public 
    void set3() {
        score = (math+physics)/2;
    }
    void get3() {
        cout<<"Score is: "<<score<<endl;
    }
};
//different set() and get() methods required as in the end all inherited to result class and in main obj of result created and setting values to protected members of other classes
//gives error as set() and get() funcs of multiple classes present
int main() {
    result x;
    x.set1(21);
    x.set2(99,100);
    x.set3();
    x.get1(); x.get2(); x.get3();
}
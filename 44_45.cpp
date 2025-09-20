#include <iostream>
using namespace std;

class student {
protected:
    int roll_no;
public:
    void set(int x) {
        roll_no = x;
    } 
    void get() {
        cout<<"roll num : "<<roll_no<<endl;
    }
};

class sports : public virtual student {
protected:
    int score;    
public:
    void set(int z) {
        score = z;
    }
    void get() {
        cout<<"score : "<<score<<endl;
    }
};
//virtual prevents future ambiguity where parent becomes virtual and if the child class(s) become parent later, methods/members of the first parent class pass only once
class test : public virtual student {
protected:
    int math, phy;
public: 
    void set(int x, int y) {
        math = x;
        phy = y;
    }
    void get() {
        cout<<"math : "<<math<<", phy : "<<phy<<endl;
    }
};

class result : public sports, public test {
protected:
    int result;
public:
    void set(int roll, int x, int y, int z) {
        student :: set(roll);
        test :: set(x, y);
        sports :: set(z);
    }
    void get() {
        student :: get();
        test::get();
        sports::get();
        cout<<"result : "<<(math+phy+score)/3<<endl;
    }
};

int main() {
    result r;//r's set() and get() funcs override test and sports set() and get() funcs during run time
    r.set(721, 100, 99, 98);
    r.get();
    
}
#include <iostream>
using namespace std;
//SWAPING VALUES OF PRIVATE DATA IN CLASSES USING CALL BY REFRENCE
class c2;
class c1 {
    int data;
    friend void swap(class c1*, c2*);//put 'class c2' here or c2 will remain undeclared for compiler and would have to add forward declaration at top
public: 
    void set(int a) {
        data = a;
    }
    void get() {
        cout<<"Value of c1 = "<<data<<endl;
    }
};

class c2 {
    int data;
    friend void swap(class c1*, c2*);
public:
    void set(int a) {
        data = a;
    }
    void get() {
        cout<<"Value of c2 = "<<data<<endl;
    }
};

void swap(class c1* x, c2* y) {//x, y object of class c1, c2
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

int main() {
    c1 a;
    a.set(5);
    c2 b;
    b.set(6);
    swap(&a, &b);
    //swapped
    a.get();
    b.get();
}
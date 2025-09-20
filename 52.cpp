#include <iostream>
using namespace std;

class shop {
    int id;
    int price;
public:
    shop(){}
    shop(int i, int p) {
        id = i;
        price = p;
    }
    void get() {
        cout<<"item : "<<id<<" has price : "<<price<<endl;
    }
};

int main() {
    shop *ptr = new shop[3];
    int a, b;
    for (int i = 0; i < 3; i++) {
        cout<<"Enter id, price : "<<endl;
        cin>>a>>b;
        *(ptr + i) = shop(a, b);//or can use ptr->set() func
    }
    for (int i = 0; i < 3; i++) {
        (ptr + i)->get();
    }
}
#include <iostream>
using namespace std;

class shop {
    int id[100];
    int price[100];
    int c;//need to define c here first in private; or below method of simply defining and initialising it in private and using it continously [PART OF INDIRECT MEHTOD]
    // int C = 0;//establishing a counter for array indexing directly in private instead of any func in public [DIRECT METHOD / STATIC COUNTER]
public:
    void Counter() {//can create a counter like this in PUBLIC -> mention func in main to start before setting prices [INDIRECT FUNC METHOD]
        c = 0;//simply, if c declared here then it's local variable of func so should be declared outside (private/public) but func only to start it from 0
    }
    void set(int i, int p) {
        id[c] = i;
        price[c] = p;
        c++;//counteer increased to store new value
    }
    void get() {//shows the entire array of items with id & price (object of this class contains a whole array of id, price) instead of just a single element 
        for (int i = 0; i < c; i++) {
            cout<<"Item id "<<id[i]<<" has price "<<price[i]<<endl;
        }
    }
};

int main() {
    shop dukan;
    dukan.Counter();//[PART OF INDIRECT METHOD]
    dukan.set(1, 20);
    dukan.set(2, 30);
    dukan.get();
    shop dukan1;
    dukan1.Counter();
    dukan1.set(1,22);
    dukan1.set(322, 400);
    dukan1.get();//both work perfectly fine with int C = 0 defined in private as well as with int c which = 0 defined in public;
}
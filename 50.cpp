#include <iostream>
using namespace std;

int main() {
    int* a = new int(4);
    cout<<"value at a : "<<*(a)<<endl;
    *a = 44;
    cout<<"value at a : "<<*(a)<<endl;
    delete a;
    cout<<"value at a : "<<*(a)<<endl;

    int* arr = new int[2];
    arr[0] = 10;
    *(arr + 1) = 20;
    cout<<"value at index 0 of arr : "<<arr[0]<<endl;
    delete[] arr;
    cout<<"value at index 0 of arr : "<<arr[0]<<endl;
}
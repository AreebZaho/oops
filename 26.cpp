#include <iostream>
using namespace std;

class complex {
    int a, b;
public: 
    void set(int n1, int n2) {
        a = n1, b = n2;
    }
    void get() {
        cout<<a<<" + "<<b<<"i"<<endl;
    }
    friend int sum(complex, complex);//sum func is now a friend of complex class so can access it's private variables outside the class
    // friend void test(complex);//[can define a friend func in private too instead of public]
    // friend void test1();//both don't need to be friend func as they have no relation to obj's private data
};
// 
int sum(complex c1, complex c2) {//not a method of class but only an outside function, [CANNOT BE ACCESSED BY A CLASS' OBJECT USING . AS NOT A CLASS METHOD]
    complex c3;
    c3.set(c1.a + c2.a, c1.b + c2.b);//invalid as directly passing complex no.s a, b to func which are private [invalid until declared a friend of class]
    return c3.a;
}
void test(complex c) {//can contain an argument complexNO. whose a, b will have operation performed on them. 
    c.set(100, 101);//friend func can access other methods of class 
    c.get();//can't use (obj.friendFunc) so need to pass obj as arg and to access OBJ's private data, use OBJ.(private data variable) in it
}
void test1() {//the point of making friend is to access it's private data
    cout<<1<<endl;
}
//CAN'T USE THE FRIEND FUNC AS MEHTOD FOR OBJECTS USING . BUT CAN USE METHODS INSIDE FRIEND FUNCS ON OUR OBJECTS-------------------------------------------------------------  
int main() {
    complex c1, c2, c3;
    c1.set(5, 6);
    c2.set(2,4);
    c3.set(1, 3);
    sum(c1, c2).get();//sum() represents a complex no. c3 and needs to be printed using class' method get();
    test(sum(c1, c2));
    sum(c1, c2).get();//copy of (c1+c2) complex no. is passed in above func and original values unchanged
    // c3.test1();//func with no argument or return value but does not work with class' objects as [THEY ARE FRIEND FUNC OF CLASS AND NOT A METHOD OF CLASS TO BE ACCESSED BY OBJECTS]
    test1();//works perfectly fine as - 1) not used as method of class' object, 2) independent of class' private data 
}

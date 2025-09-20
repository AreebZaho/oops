#include <iostream>
#include <cmath>
using namespace std;

class point {
    int x, y;
    friend void distance2points(point, point);
public:
    point();//default constructor
    point(int, int);//parameterised constructor
    //get() is a method that inputs values in obj's data types while constructor is invoked with object creation and can be default or parameterised
    void get() {
        cout<<x<<", "<<y<<endl;
    }
};

point::point() {//accepts no parameters
    x = 0, y = 0;
    cout<<"Obj created so constructor invoked and this line of default constructor getting executed too"<<endl;
}

point::point(int a, int b) {//NECESSARY TO MAKE A DEFAULT CONSTRUCTOR IF MAKING A CONSTRUCTOR OR WOULD'VE TO USE CONSTRUCTOR DIRECTLY WITH DEFINING OBJ IN MAIN
    x = a, y = b;           //LIKE [CLASS NAME] [OBJ](VALUES); OR [CLASS NAME] [OBJ] = [CLASS NAME](VALUES);
    cout << "parameterized constructor invoked" << endl;
}

void distance2points(point o1, point o2) {
    float dist = sqrt(((o1.x - o2.x)*(o1.x - o2.x))+((o1.y - o2.y)*(o1.y - o2.y)));
    cout<<dist<<" sq units"<<endl;
}

int main() {
    point c;//default constructor invoked and all statements in default constructor executed   
    c = point(0,1);//parameterised c here
    //implicit call:
    point c1(4, 6);
    //explicit call:
    point c2 = point(5, 7);
    c.get(), c1.get(), c2.get();   
    distance2points(c1, c2);
}
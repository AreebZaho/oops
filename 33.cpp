#include <iostream>
using namespace std;

class bank
{
    float principal;
    int years;
    float rate;
    float returns;

public:
    bank(){};              // defualt constructor
    bank(int, int, int);   // int rate out of 100
    bank(int, int, float); // float rate out of 1, overloading of constructors
    void get();
};

bank::bank(int p, int y, int r)
{
    principal = p;
    years = y;
    rate = (float)r / 100; // typecasting to float so 0.something doesn't become 0
    returns = principal;
    for (int i = 0; i < y; i++)
        returns = returns + returns * rate;
}
bank::bank(int p, int y, float r)
{
    principal = p;
    years = y;
    rate = r;
    returns = principal;
    for (int i = 0; i < y; i++)
        returns = returns + returns * rate;
}
void bank::get()
{
    cout << principal << " returns " << returns << " after " << years << " year at interest rate " << rate << endl;
}

int main()
{
    bank b1, b2, b3;
    b1 = bank(100, 1, 0.05f); // takes decimal values as double by default so always input as variable or with f
    b1.get();
    b2 = bank(100, 1, 5);
    b2.get();
}
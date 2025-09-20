#include <iostream>
using namespace std;

template <class T>
class Vector
{
public:
    T *arr;
    int n;
    Vector(int size)
    {
        n = size;
        arr = new T[n];
    }
    T dotProduct(Vector &v)
    {
        T ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += this->arr[i] * v.arr[i];
        }
        return ans;
    }
};

template <class T1 = int, class T2 = float>
class Test
{
public:
    T1 a;
    T2 b;
    void display()
    {
        cout << a << " " << b << endl;
    }
};

template <class T1, class T2>
double sum(T1 a, T2 b)
{
    return a + b;
}

template <class T>
void swap(T &a, T &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

template <class T>
class A
{
public:
    T a;
    A(T a)
    {
        this->a = a;
    }
    void display();
};
template <class T>
void A<T>::display()
{
    cout << a << endl;
}

void fun(int a) {
    cout << "normal func " << a << endl;
}
template <class T>
void fun(T a) {
    cout << "normal func " << a << endl;
}

int main()
{
    Vector<float> v1(3), v2(3);
    v1.arr[0] = 1.1;
    v1.arr[1] = 1.2;
    v1.arr[2] = 1.3;
    v2.arr[0] = 2.1;
    v2.arr[1] = 2.2;
    v2.arr[2] = 2.3;
    cout << v1.dotProduct(v2) << endl;
    Test<> t; //* default int, float applied
    t.a = 1;
    t.b = 5.5;
    t.display();
    cout << sum(3.0033, 4);
}
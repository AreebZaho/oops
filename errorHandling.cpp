#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int a = 10, b = 0;
    // try
    // {
    //     if (b == 0)
    //         throw runtime_error("dividing by zero"); //* can be normal string as well throw "";
    //     cout << "division result: " << a / b << endl;
    // }
    // catch (runtime_error &e) //* can be (const char* e) as well
    // {
    //     cout << "Exception occured: " << e.what(); //* use e normally if (const char* e)
    // }
    //? multiple catch blocks
    try
    {
        throw 'a';
    }
    catch (const char *e)
    {
        cout << "Exception occured: " << e;
    }
    catch (int e)
    {
        cout << "Exception occured: " << e;
    }
    catch (runtime_error &e)
    {
        cout << "Runtime exception occured: " << e.what();
    }
    catch (...)
    {
        cout << "some exception occured";
    }
}
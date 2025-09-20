#include <iostream>
#include <stdexcept>
using namespace std;

void test() throw(int, char, runtime_error) {
    // throw 20;
    throw 'a';
}

int main() {
    try {
        test();
    }
    catch (int e) {
        cout << "int type error: " << e << endl;
    }
    catch (char e) {
        cout << "char type error: " << e << endl;
    }
    catch (runtime_error &e) {
        cout << "runtime error: " << e.what() << endl;
    }
}
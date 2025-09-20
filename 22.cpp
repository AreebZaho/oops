#include <iostream>
using namespace std;

class binary {
    string s;
public:
    void get(string bin) {
        s = bin;
    }
    void display() {
        if (check())
        cout<<s<<endl;
        else cout<<"not binary"<<endl;
    }
    int check() {//can also make this func private as it is not being used in main and only used by class funcs which can access it even though it's private
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '1' && s[i] != '0') {
                return 0;
            }
        }
        return 1;
    }
    void complement() {
        if (check())
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
            s[i] = '0';
            else s[i] = '1';
        }
    }
};

int main() {
    binary i;
    i.get("10103");
    i.display();
    i.complement();
    i.display();
}
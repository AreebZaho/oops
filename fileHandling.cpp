#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string s = "Writing in Sample.txt file";
    //? writing in file
    // ofstream out("sample.txt");
    //* or can use out.open(""); if don't want to use constructor
    // out << s;
    // out.close();
    //? reading from file
    string read;
    ifstream in("sample.txt");
    // in >> read;
    // getline(in, read); // gets only 1 line
    // cout << read << endl;
    // getline(in, read);
    // cout << read; // gets secod line
    while (!in.eof())
    {
        getline(in, read);
        cout << read << endl;
    }
    in.close();
}
#include <iostream>
using namespace std;

class CWH {
protected:
    string title;
    int rating;
public:
    CWH(){}
    CWH(string title, int rating) {
        this->title = title;
        this->rating = rating;
    }
    virtual void get() {//if it weren't virtual then CWH's pointer pointing to it's derived class would have printed this get() only 
        cout<<"nothing to see here"<<endl;
    }
};

class CWHvideo : public CWH {
protected:
    int vidlength;
public:
    CWHvideo(string title, int rating, int vidlength) : CWH(title, rating) {
        this->vidlength = vidlength;
    }
    void get() {
        cout<<title<<endl;
        cout<<"Rated : "<<rating<<endl;
        cout<<vidlength<<" mins long"<<endl;
    }
};

class CWHtext : public CWH {
protected:
    int wordsNo;
public:
    CWHtext(string title, int rating, int wordsNo) : CWH(title, rating) {
        this->wordsNo = wordsNo;
    }
    void get() {
        cout<<title<<endl;
        cout<<"Rated : "<<rating<<endl;
        cout<<wordsNo<<" words"<<endl;
    }
};

class CWHtest : public CWH {
};

int main() {
    CWHvideo v("C++ Video Tutuorial", 9, 10);
    CWH* CWHptr = &v;

    CWHtext t("C++ Text Tututorial", 9, 1004);
    CWH* CWHptr1 = &t;

    CWHptr->get();
    cout<<endl;
    CWHptr1->get();
    cout<<endl;

    CWHtest test;//class doesn't have get() func of it's own
    CWH* CWHptr2 = &test;//so when base class' pointer pointed to it's object 
    CWHptr2->get();//calls base's get() only

    // virtual functions:
    // can't be static 
    // accessed by pointers
    // can be friend of another class
    // might not be used in base class (acts as abstract method)
    // need not be used in derived class (where pointer of base calls get() but not in CWHtest so prints base's get() only)
}
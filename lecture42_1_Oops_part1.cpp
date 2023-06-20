#include<bits/stdc++.h>
using namespace std;

class Hero{

    char level1; //we can only access this properties of class within the class since it lies into the private section

    public:
    int health; //one can access these properties anywhere by using a dot(.) operator
    char level;

    void print() {
        cout << level << endl;
        cout << level1 << endl;
    }
};


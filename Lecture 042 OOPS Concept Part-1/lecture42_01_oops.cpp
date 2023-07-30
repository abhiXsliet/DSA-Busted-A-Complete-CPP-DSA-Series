#include<bits/stdc++.h>
using namespace std;

class Hero{
// The properties of the class can only be accessed from within the class itself because they are located in the private section.
    char level1; 

    public:
    int health; //one can access these properties anywhere by using a dot(.) operator
    char level;

    void print() {
        cout << level << endl;
        cout << level1 << endl;
    }
};


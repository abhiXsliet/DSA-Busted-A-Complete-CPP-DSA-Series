#include<bits/stdc++.h>
using namespace std;

// Static Keyword


class Hero {
    
    int health;

    public:     
    char* name; //char name[100] :-> bad practice so that one should do it dynamically
    char level;
    static int timeToComplete;


    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }  

    void setLevel(char ch) {
        level = ch;
    }  

    void setName(char name[]) {
        strcpy(this ->name, name);
    }

};

//initialise
//data type :: field Name = value (:: = scope resolution operator)

int Hero :: timeToComplete = 5;

int main() {

    cout << Hero::timeToComplete << endl;

    Hero a;

    //not recommended at all since this static member not belongs to objects but class
    cout << a.timeToComplete << endl;

    Hero b;
    b.timeToComplete = 10;
    cout << a.timeToComplete << endl;
    cout << b.timeToComplete << endl;

    cout << endl;
    return 0;
}
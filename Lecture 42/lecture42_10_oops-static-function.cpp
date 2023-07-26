#include<bits/stdc++.h>
using namespace std;

//static function (properties:)
//1. not need to create object. Since you can directly call this fn. by their class name 
//2. Since here is no current object so, this keyword is not here because this keyword is a pointer to current object
//3. static fn. can only access static member


// Static Keyword

class Hero {
    
    int health;

    public:     
    char* name; //char name[100] :-> bad practice so that one should do it dynamically
    char level;
    static int timeToComplete;

    static int random() {
        // wrong => cout << health << endl;
        // wrong => cout << level << endl;
        // wrong => cout << name << endl;

        return timeToComplete;
    }

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

int Hero :: timeToComplete = 5;

int main() {

    cout << Hero :: random() << endl;

}
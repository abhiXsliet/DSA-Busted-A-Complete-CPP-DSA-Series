#include<bits/stdc++.h>
using namespace std;

//DESTRUCTOR :- is used to de-allocation of memory
//properties : 
//1. name is same as class
//2. no return type
//3. no input parameter

class Hero {
    
    int health;

    public:     
    char* name; //char name[100] :-> bad practice so that one should do it dynamically
    char level;

    ~Hero() {
        cout << "Destructor bhai called " << endl;
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

int main() {

    //static
    Hero a; 
    // In static, destructor gets automatically called by the compiler
    // destructor is automatically created when a class is created but one can also manually create a destructor. 
    // After manual creation of any type of destructor previous default destructor gets terminated.

    //dynamic
    Hero *b = new Hero();
    //for dynamic, destructor have to manually called by the user
    delete b;

    return 0;


}

//HW : what is 'const' keyword? How it used in object creation? How const keyword is used in data member? How one can create const type function?
// Initialisation list concept?


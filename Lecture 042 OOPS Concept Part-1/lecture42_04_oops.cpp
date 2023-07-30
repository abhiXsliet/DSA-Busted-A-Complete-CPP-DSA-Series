#include<iostream>
using namespace std;

class Hero {
    
    //properties
    private:
    int health;

    public:
    char level;

    // After manual creation of constructor either default or parameterized
    // previous default constructor gets eliminated by the compiler
    Hero() {
        cout << "DEFAULT constructor called" << endl;
    }

    // Parameterized constructor
    // 'this' keyword came into play when we use same i/p parameter and the data member
    // this is a pointer who is representing the data member int health.
    Hero(int health){
        cout << "this => " << this << endl;
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    void print() {
        cout << level << endl;
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
    
};


int main() {

    // static allocation
    Hero a;

    a.setHealth(50);
    a.setLevel('B');

    cout << endl;

    // accessing data member by using dot(.) operator
    cout << "Level is :  " << a.level << endl;
    cout << "health is : " << a.getHealth() << endl;
    cout << endl << endl;


    // dynamically
    Hero *b = new Hero;

    (*b).setHealth(90);
    b->setLevel('X'); //or (*b).setLevel('X');

    // accessing data member in dynamically by using either dot-operator(.) and de-reference operator(*) or ->
    cout << "Level is :  " << (*b).level << endl;
    cout << "health is : " << (*b).getHealth() << endl;

    cout << "Level is (->) :  " << b->level << endl;
    cout << "health is(->) : " << b->getHealth() << endl;



    return 0;
}
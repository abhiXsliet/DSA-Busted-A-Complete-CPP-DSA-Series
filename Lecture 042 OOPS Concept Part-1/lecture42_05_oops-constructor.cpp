#include<iostream>
using namespace std;

class Hero {
    
    //properties
    private:
    int health;

    public:
    char level;

    //DEFAULT constructor creation , after manual creation of default constructor previous default constructor will be eliminated by the compiler
    Hero() {
        cout << "DEFAULT constructor called" << endl;
    }

    //**when you created any type of your own constructor either parameterized or default then previous default constructor gets terminated

    //Parameterized constructor
    //'this' keyword came into play when we use same i/p parameter and the data member
    //this is a pointer who is representing the data member int health.
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

//** whenever we create an object then their constructor is called by the compiler
//Constructor ?
//properties of constructor : 1. envoke during object creation 2. no return type 3.right below we just saw has no i/p parameter also

int main() {

    //object created statically
    cout << "Hi" << endl;
    Hero ramesh;
    //after objected being created a DEFAULT CONSTRUCTOR ENVOKED (i.e., ramesh.Hero()) by the compiler bts;
    cout << "Hello" << endl;

    cout << endl << endl;

    //objected created dynamically
    cout << "before dynamic object  " << endl;
    Hero *s = new Hero; //new Hero || new Hero() no difference at all
    //same constructor will be called in case of dynamically created object as it was called during statically created object
    cout << "after dynamic object " << endl;
    s -> print(); //valid only for dynamically created object

    cout << endl << endl;

    Hero kalia(10);
    cout << "Address of kalia => " << &kalia << endl;

    cout << endl << endl;

    Hero temp(22, 'F');
    cout << "health of temp is :=> " << temp.getHealth() << endl;
    cout << "level of temp :=> " << temp.getLevel() << endl;
    cout << "------------Another Way----------" << endl;
    temp.print();

    cout << endl << endl;
    return 0;
}
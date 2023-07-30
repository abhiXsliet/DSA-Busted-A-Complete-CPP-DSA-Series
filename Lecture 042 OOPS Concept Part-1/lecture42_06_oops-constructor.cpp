#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    private:
    int health;

    public:     
    char level;

    Hero() {
        cout << endl;
        cout << "Simple constructor called " << endl;
    }

    //parameterized constructor
    Hero(int health) {
        this -> health = health;
    }

    Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    }

    //copy constructor //** when you created your own copy constructor then previous default copy constructor gets terminated
    Hero(Hero& temp) { //& why? watch at (55:00)
        
        cout << "copy constructor called" << endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "health : " << this -> health << endl;
        cout <<  "level : " << this -> level << endl;
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

    Hero s(70, 'C');
    s.print();

    cout <<  endl;

    //copy constructor
    Hero R(s);
    R.print(); 

    return 0;
}
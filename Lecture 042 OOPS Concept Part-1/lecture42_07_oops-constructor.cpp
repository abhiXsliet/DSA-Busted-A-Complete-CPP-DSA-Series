#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    int health;

    public:     
    char* name; //char name[100] :-> bad practice so that one should do it dynamically
    char level;


    Hero() {
        cout << endl;
        cout << "Simple constructor called " << endl;
        name = new char[100]; //allocating memory of array on heap dynamically
    }

    //parameterized constructor
    Hero(int health) {
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp) {
        
        //deep copy
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this -> name = ch;

        cout << "\nCopy constructor called " << endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    }

    void print(){
        cout << endl;
        cout << "[ name : " << this -> name << ", " ;
        cout << "health : " << this -> health << ", ";
        cout <<  "level : " << this -> level << " ]";
        cout << endl ;
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
    
    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[9] = "Babbar";
    hero1.setName(name);

    hero1.print();

    //use default copy constructor

    Hero hero2(hero1);  //Hero hero2 = hero1;
    hero2.print();

    //shallow copy
    hero1.name[0] = 'G';
    hero1.print();

    //deep copy
    hero2.print();


    //copy Assignment Operator
    hero1 = hero2;
    
    hero1.print();
    hero2.print();

    cout << endl << endl;


    return 0;
}

//documentation code studio : https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382186
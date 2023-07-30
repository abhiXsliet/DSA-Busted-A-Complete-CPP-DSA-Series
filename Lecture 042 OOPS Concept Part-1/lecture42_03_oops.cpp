#include<iostream>
using namespace std;

class Hero {

    private:
    int health2;
    char level2 = 'B';

    public:
    int health;
    char level;

    // direct printing in class is wrong
    // cout << "We can access level2 here => " << level2 << endl;
    void print() {
        cout << "We can access level2 here => " << level2 << endl;
    }


    // getter :- are used to simply fetch
    char getLevel() {
        return level2;
    }

    int getHealth2() {
        return health2;
    }

    // setter :- are used to change the values by the user after fetching
    // it also used as to implement some specific condition or password
    // so if the codn. occurs then only one can change the value of setter
    void setHealth2(int h) {
        health2 = h;
    }

    void setLevel(char ch) {
        level2 = ch;
    }
    
};

class Hero2 {


};

int main() {

    // object instanciated
    // statically allocation
    Hero ramesh;


    // dynamically allocation
    Hero *b = new Hero;

    
    // setting object values(properties)
    ramesh.health = 10;
    ramesh.level = 'Z';

    cout << "\nHealth of Hero is : " << ramesh.health << endl;
    cout << "level of Hero is : " << ramesh.level << endl;

    //cout << "level2 of Hero is : " << ramesh.level2 << endl;
    // we can't access the level2 because it lies into the private section

    cout << endl << endl;

    //** If one want to access the private memebers of the class then can be done by using getter and setter;
    cout << "ramesh level2 is :=> " << ramesh.getLevel() << endl;
    cout << "ramesh health2 is :=> " << ramesh.getHealth2() << endl << endl ;
    
    ramesh.setHealth2(100);
    cout << "ramesh health after setter :=> " << ramesh.getHealth2() << endl << endl;

    cout << "size of health2 is :=> " << sizeof(ramesh.getHealth2()) << endl << endl;

    cout << "size of object ramesh (Hero class) => " << sizeof(ramesh) << endl  << endl;
    Hero2 unknown;
    cout << "size of unknown is (empty class Hero2) :=> " << sizeof(unknown) << endl << endl << endl;
    
    /////////////////////////////////////////////////////////////
    /////   HW := read about padding and greedy alignment   /////
    /////////////////////////////////////////////////////////////
    
    // Processor doesn't read 1-byte at a time, it read 1-word at a time which is equal to 4-bytes in 32-bit processor and 8-bytes in 64-bit processor.
    // To avoid the un-necessary wastage of cpu cycle concept of padding was introduced. The padding is done automatically by the compiler.
    // If we change the order of variables then their value of o/p also changes because padding works differently
    // Link : https://www.javatpoint.com/structure-padding-in-c
    // disadvantage of padding is that wastage of memory occurs in padding.

    // Alignment refers to the arrangement of the data in the memory and specifically deals with the issue of accessing data as proper units of informatioin from the main memory.



    return 0;
}
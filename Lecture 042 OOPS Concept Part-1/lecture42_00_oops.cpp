#include<bits/stdc++.h>
using namespace std;

// Objects oriented programming is a type of programming paradime/style 
// in which programs based upon or revolves around the real world objects so, that the readability, managability, extensiviability of program increases

// Objects is a entity which has its own -> 1. state/properties and 2. behaviour

// class is a user defined data type for e.g., Hero Ramesh => Here, Ramesh is a variable of Hero type

// Objects are instance of class

// creation of a class
class Hero {

    // properties
    int health;

};

int main() {

    // creation of an object
    Hero h1;

    cout << "Size : " << sizeof(h1) << endl << endl;
    //*** In Empty class the size allocated to the memory is 1-byte just to keep the track of the class
    
    cout << endl;
    return 0;
}
#include <iostream> 
using namespace std;

// Hybrid Inheritance
// combination of more than one type of inheritance 
// For e.g., class B and class C inheriting from class A. At the same time class C is also inheriting from the class D 
// Above example is the combn. of single and hierarchical type of inheritance.

// Parent class1 
class Vehicle { 
    public: Vehicle() { 
        cout << "This is a Vehicle" << endl; 
    } 
}; 

//Parent class2 
class Fare { 
    public: Fare() 
    { 
        cout << "Fare of Vehicle\n"; 
    } 
}; 

//Child class1 
class Car: public Vehicle { }; 

//Child class2 
class Bus: public Vehicle, public Fare { }; 

// main function 
int main() { 
    // creating object of sub class will 
    // invoke the constructor of base class 
    Bus obj2; 
    
    cout << endl;
    return 0; 
} 
#include <iostream>
using namespace std;

// Run-Time Polymorphism (dynamic polymorphism)
// inheritance is important since it depends on it
// Method Overriding :- when you write your own statement in the function and then inheriting it. Hence, it is known as function overriding


class Animal { 
    public:
    void speak() {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal {
    public:

    void speak() {
        cout << "Barking" << endl;
    }

};

int main() {
    Dog obj;
    obj.speak();

    //incase there is no speak function in the class Dog then it get called from the Animal class.
    cout << endl;
    return 0;
}
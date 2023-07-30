#include <iostream>
using namespace std;


//Multiple Inheritance
//class A , class B => class C
//Here, class C is inheriting from the both classes: class A and class B

class Animal {

    public:
    int age;
    int weight;

    public:
    void bark() {
        cout << "Barking " << endl;
    }

};


class Human {

    public:
    string color;

    public:
    void speak() {
        cout << "Speaking " << endl;
    }
};

//multiple inheritance
class Hybrid : public Animal, public Human {

};

int main() {

    Hybrid object1;
    object1.speak();
    object1.bark();

    return 0;
}
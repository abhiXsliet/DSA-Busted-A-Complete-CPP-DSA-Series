#include<bits/stdc++.h>
using namespace std;

// from class A, class B is inheriting =>  SINGLE INHERITANCE
// class Male is inheriting their properties from class Human 

class Animal {
    public:

    int age;
    int weight;

    public:
    void speak() {
        cout << "speaking " << endl;
    }
};

class Dog : public Animal {

};

int main() {

    Dog d;
    d.speak();
    cout << d.age << endl;

    cout << endl;
    return 0;
}
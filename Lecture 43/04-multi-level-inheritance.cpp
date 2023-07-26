#include<bits/stdc++.h>
using namespace std;

// class A => class B => class C => class D => class E
// Here class B is inheriting its properties from class A, and class C is inheriting its properties from class B and so on. 
// This type of inheritance is considered as the multi-level inheritance

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

class GermaShephard : public Dog {

};


int main() {
    
    //multi-level inheritance
    Dog d;
    d.speak();
    cout << d.age << endl;

    return 0;
}
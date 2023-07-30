#include <iostream>
using namespace std;

// POLYMORPHISM
// poly = many, morp = forms

// polymorphism meaning is existing in multiple forms

// 2-types of polymorphism :-
// (1). compile time polymorphism
// (2). Run time polymorphism


// COMPILE TIME POLYMORPHISM :- Since this process is executed during compile time, that's why it is known as Compile-Time Polymorphism.
// Also known as static polymorphism
// This type of polymorphism can be achieved through function overloading or operator overloading

#include<iostream>
using namespace std;

class A {

    public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }

    //function overloading with an argument
    void sayHello(string name) {
        cout << "Hello using overloaded function" << endl;
    }

    //function overloaded with different argument
    int sayHello(char name) {
        cout << "Hello Love Babbar Bhai" << endl;
        return 1;
    }
};

int main() {
    A obj;
    obj.sayHello();

    return 0;
}

//code studio reference link : https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382250
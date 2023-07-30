#include <iostream>
using namespace std;

// Hierarchical inheritance;
// one class serves as a parent class for more than one class;

class A {

    public:
    void func1() {
        cout << "Inside function 1" << endl;
    }
};

class B : public A {

    public:
    void func2() {
        cout << "Inside function 2" << endl;
    }
};

class C : public A {

    public:
    void func3() {
        cout << "Inside function 3" << endl;
    }
};

int main() {
    
    A object1;
    object1.func1();

    B object2;
    object2.func2();
    object2.func1();

    C object3;
    object3.func1();
    //object3.func2(); //ERROR since class C is not inheriting from class B so, func2() cannot be called by the compiler.
    object3.func3();
}


// why? we are doing different type of inheritance
// HW : go to the documentation of code studio and read the reason
// https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382233

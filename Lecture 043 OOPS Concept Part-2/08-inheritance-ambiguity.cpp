#include <iostream>
using namespace std;
 
// Inheritance Ambiguity

// If parent class-1 and parent class-2 have the same member ( void abc())
// class-c is inheriting from both classes 1&2 then because of their same member name term inheritance ambiguity arises.
// to avoid inheritance ambiguity, one should use the scope resolution opr(::)


class A {
    public:
    void func() {
        cout << " I am func from class A" << endl;
    }
};

class B {
    public:
    void func() {
        cout << " I am func from class B" << endl;
    }
};

class C : public A, public B {};

int main( ) {

    C object;
    //object.func() //Error: inheritance ambiguity

    object.A :: func();
    object.B :: func();

    cout << endl;
    return 0;
}
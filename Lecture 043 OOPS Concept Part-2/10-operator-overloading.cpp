#include <iostream>
using namespace std;

// Operator Overloading

class B {
    public:
    int a ;
    int b ;

    public:
    int add () {
        return a+b;
    }

    //operator is being overloaded => syntax => [return-type    operator+   (i/p argument)]
    void operator+ (B &obj) {
        int value1 = this -> a;
        int value2 = obj.a;
        cout << "Output => " << value2 - value1 << endl;

    }

    void operator() () {
        cout << "Main Bracket hu => value of a : " << this -> a << endl;
    }
};

int main() {

    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    cout << endl;
    return 0;
}
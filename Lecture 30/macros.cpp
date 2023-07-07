#include<iostream> 
using namespace std;

// Using #define we can create macros
// macro is a piece of code in a program that is replaced by the value of macro. 
// It does not take any extra storage like variables.
// whenever a macro is encountered by the compiler, it replaces the name with the definitions of the marcro.
// macro definitions need not to be terminated by the semi-colon.

#define PI 3.14

int main() {

    int r = 5;
    //double pi = 3.14;

    double area = PI * r * r;

    cout << "Area is " << area << endl;

    return 0;
}
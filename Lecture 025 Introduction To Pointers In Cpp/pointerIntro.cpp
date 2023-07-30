#include<iostream>
using namespace std;

int main(){
    int num = 5;

    cout << num << endl;
    
    // address of Operator - &
    cout << "Address of num is "  << &num << endl;

    // pointer(*) stores the address 

    // Bad practice -> *ptr is pointing to some garbage address since it is pointing anywhere in the memory location
    // int *ptr

    // pointer declaration
    // int *ptr = 0; //null pointer

    // ptr is a pointer to int and * is a dereference operator
    int *ptr = &num; 

    cout << "Address is :-> " << ptr << endl;
    cout << "Value present at address is :-> " << *ptr << endl;

    double d = 4.3;
    double *p2 = &d; // p2 is a pointer to double

    cout << "Address is : " << p2 << endl;
    cout << "Value is : " << *p2 << endl;

    char v = 'x';
    char *p3 = &v; // p3 is a pointer to char
    cout << "Address is => " << p3 << endl;
    cout << "Value is => " << *p3 << endl;

    cout << endl;

    // It is 8-bytes of size for all type of pointer wheather int/char/double
    cout << "Size of integer num--> "<< sizeof(num)<< endl << endl;
    cout << "Size of pointer ptr--> "<< sizeof(ptr)<< endl;
    cout << "Size of pointer p2 --> "<< sizeof(p2) << endl;
    cout << "Size of pointer p3 --> "<< sizeof(p3) << endl;

    cout << endl;
    return 0;
}

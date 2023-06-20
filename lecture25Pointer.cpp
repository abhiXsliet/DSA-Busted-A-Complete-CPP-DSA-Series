#include<iostream>
using namespace std;

int main(){
    int num = 5;

    cout << num << endl;
    
    //address of Operator - &
    cout << "Address of num is "  << &num << endl;

    //pointer(*) stores the address 

    //very bad practice. Here pointer p is created and pointing to some garbage address since the pointer is pointing anywhere in the memory 
    //int *ptr

    //pointer declaration;
    //int *ptr = 0; //null pointer

    int *ptr = &num; //p is a pointer to int and here * is a dereference operator

    cout << "Address is :-> " << ptr << endl;
    cout << "Value present at address is :-> " << *ptr << endl;

    double d = 4.3;
    double *p2 = &d;//p2 is a pointer to double

    cout << "Address is : " << p2 << endl;
    cout << "Value is : " << *p2 << endl;

    char v = 'x';
    char *p3 = &v; //p3 is a pointer to char
    cout << "Address is => " << p3 << endl;
    cout << "Value is => " << *p3 << endl;

    cout << endl;

    cout << "Size of integer num--> "<< sizeof(num)<< endl << endl;
    cout << "Size of pointer ptr--> "<< sizeof(ptr)<< endl;
    cout << "Size of pointer p2 --> "<< sizeof(p2) << endl;
    cout << "Size of pointer p3 --> "<< sizeof(p3) << endl;
    //here you'll be getting 4-byte size for pointers but Actually it is 8-byte for all type of pointer wheather int/char/double

    cout << endl;


    int *p = &num;
    cout << "Before -> " << num << endl;
    (*p)++;

    cout << "After -> " << num << endl << endl;


    //copying a pointer
    int *q = p;
    cout << p << " - " << q << " - " << &num << endl;
    cout << *p << " - " << *q << " - " << num << endl << endl;
    
    //important concept
    int i = 3;
    int *t = &i;

    //cout << (*t)++ << endl;
    *t = *t + 1;
    cout << *t << endl;
    cout << "Before t => " << t << endl;

    t = t + 1 ; //address will be incremented by 4 byte
    cout << "After t => " << t << endl << endl;

    return 0;
}


//read the coding ninja attachment from the desprition and solve the question to become champ 

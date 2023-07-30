#include<iostream>
using namespace std;

int main()
{
 
    cout << "Hello Duniya walon" << endl;
    cout << "Chaliye Suru karte hai \n" ;
    cout << "\n" ;
    
    int a = 123;
    cout << a << endl;

    char a1 = 'v'; /* you can only store one character in a single intervted comma */
    cout << a1 << endl;

    bool bl = true;
    cout << bl << endl;
    
    float f = 2.1;
    cout << f << endl;

    double d = 1.232;
    cout << d << endl;

    int size = sizeof(a);
    cout << "size of a is: " << size << endl;

    int sizechara1 = sizeof(a1);
    cout << "size of char a1 is: " << sizechara1 << endl;

    int sizeboolbl = sizeof(bl);
    cout << "size of bool bl is: " << sizeboolbl << endl;

    int sizefloatf = sizeof(f);
    cout << "size of float f is: " << sizefloatf << endl;

    int sizedouble = sizeof(d);
    cout << "size of double d is: " << sizedouble << endl;

    int a2 = 'a';
    cout << a2 << endl;

    int a3 = 'b';
    cout << a3 << endl;

    int al = 'z';
    cout << al << endl;

    char ch = 98;
    cout << ch << endl;

    char ch2 = 120;
    cout << ch2 << endl;

    /*char ch3 = 123456;
    cout << ch3 << endl;  By running this code you will get warning regarding conversion because 
                                in integer last byte no. is only stored i.e., 64 will be transfered to char. 
                                therefore it will print @ */


    unsigned int a6 = -112; 
    cout << a6 << endl;  /* you will get a very long no. since unsigned int doesn't support a -ve no. 
                        It happens because MSB (most significant bit) is 1 due to -ve sign and treat it as a +ve no. therefore the value will be very large no.*/

  /*OPERATORS*/
    
    int a7 = 2;
    cout << a7/5 << endl;

    float a8 = 2.0;
    cout << a8/5 << endl;

    double a9 = 4;
    cout << a9/6 << endl;

    /* RELATIONAL OPERATORS */

    int ax = 2;
    int bx = 3;

    bool first = (ax==bx);
    cout << first << endl;

    bool second = (ax<=bx);
    cout << second << endl;

    bool third = (ax>=bx);
    cout << third << endl;

    bool fourth = (ax<bx);
    cout << fourth << endl;

    bool fifth = (ax>bx);
    cout << fifth << endl;

    bool sixth = (ax!=bx);
    cout << sixth << endl;

    /* LOGICAL OPERATORS &&, ||, ! */

    int ax1 = 23;
    cout << !ax1 << endl;

    int ax2 = 0;
    cout << !ax2 << endl;

}
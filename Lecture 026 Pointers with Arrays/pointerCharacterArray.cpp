#include<iostream>
using namespace std;

int main(){

    //CHARACTER & ARRAY DIFFERENCE
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout << arr << endl;

    //Attention here
    cout << ch << endl;

    char *c = &ch[0];
    //print entire string
    cout << c << endl;

    // watch at 41:57 - 46:00 something important
    char temp = 'z';
    char *p = &temp; 

    cout << p << endl;


    return 0;
}
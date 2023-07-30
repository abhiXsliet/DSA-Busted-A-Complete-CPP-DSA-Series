#include<iostream>
using namespace std;




int main(){

    int a = 1;
    int b = a++;
    int c = ++a;
    cout << b << endl;  // 1
    cout << c << endl;  // 3
}

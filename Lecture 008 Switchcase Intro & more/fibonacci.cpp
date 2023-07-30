#include<iostream>
using namespace std;

//Return nth fibonacci series
int main(){
    int a, b, n, nextNumber;
    cout << "\nEnter the nth number of the series: ";
    cin>>n;
    a = 0;
    b = 1;
    for (int i=1; i<=n; i++){
        nextNumber = a+b;
        a = b;
        b = nextNumber; 
        cout << "a = " << a << " -> " << "b = " << b << endl;
    }
    cout << endl;
    cout << n << "th number of fibonacci will be : "<< nextNumber ;
    cout << endl << endl;
}
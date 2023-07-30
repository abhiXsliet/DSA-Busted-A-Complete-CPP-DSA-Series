#include<iostream>
using namespace std;



//fibonacci series means any number is the sum of pervious two numbers
int main(){

    int n;
    cout << "enter a numeric value of n" << endl;
    cin>>n;

    int a = 0;
    int b = 1;
    cout << a << " " << b << " " ;

    //fibonacci series using for loop
    for (int i = 1; i<=n ; i++){

        int nextNumber = a+b;
        cout << nextNumber << " ";

        a = b;
        b = nextNumber;

    }

    return 0;
}
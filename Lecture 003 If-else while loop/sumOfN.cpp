#include<iostream>
using namespace std;



int main(){

    int n;
    cout << "n = ";
    cin>>n;

    // Sum of numbers from 1 to n
    // int i = 1;
    // int sum = 0;
    // while(i<=n){
    //     sum = i + sum;
    //     i = i+1;
    // }
    //     cout << "The value of sum is: " << sum << " " << endl;


    
    //sum of even no.s from 1 to n
    int i = 2;
    int sum = 0;
    while (i<=n){
        sum = i + sum;
        i = i + 2;
    }
    cout << "The sum of all even numbers in between the provided number is: " << sum << endl;

    return 0;
}
 
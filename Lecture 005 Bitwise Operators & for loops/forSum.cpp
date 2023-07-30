#include<iostream>
using namespace std;


//find the sum of n numbers using the for loop
int main(){

    int n;
    cout << "enter the value of n"<<endl;
    cin>>n;

    cout << "printing the sum from 1 to n is: "<<endl;
    
    int sum = 0;

    for (int i=1; i<=n ; i++){
        
        //sum = sum + i;
        sum += i;

    }
    cout << sum << endl;

    return 0;
}
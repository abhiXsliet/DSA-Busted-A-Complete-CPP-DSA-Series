#include<iostream>
using namespace std;


//cheking prime number;
bool isPrime(int n){

    for (int i = 2; i<n ; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int n;
    cout<<"enter a value of n: ";
    cin>>n;
    if (isPrime(n)){
        cout << n << " is a prime no." <<endl;
    }
    else{
        cout << n << " is not a prime no." <<endl;
    }

    return 0;
}


#include<iostream>
using namespace std;



int main(){

    int n;
    cout << "n = ";
    cin>>n;

    // // Check prime no using while loop
    // int i = 2;
    // while(i<n) {
    //     if(n%i==0) {
    //         cout << "Not prime for " << i << endl;
    //     }
    //     else{
    //         cout << "Prime for " << i << endl;
    //     }
    //     i = i +1;
    // }

    

    // check prime number using for loop
    bool isPrime = 1;
    for (int i = 2; i < n; i++)
    {
        if(n%i == 0)
        {
            isPrime = 0;
            break;

        }
    }
    if (isPrime == 0)
    {
        cout<< n <<" is not a prime no."<<endl;
    }
    else{
        cout<< n <<" is a prime no."<<endl;
    }

    return 0;
}

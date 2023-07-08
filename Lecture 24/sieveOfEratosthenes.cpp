#include<bits/stdc++.h>
using namespace std;

//Time complexity will be O( log(logn) )
void sieveOfEratosthenes(bool prime[]){

    //Marking every number as a prime number
    for(int i=2; i<=1000000; i++) {
        prime[i] = true;
    }

    for(int i=2; i<=1000000; i++) {
        if(prime[i])
        {   
            //Marking every mulptiles of respective number as non-prime
            for(int j=i*2; j<=1000000; j+=i) {
                prime[j] = false;
            }
        }
    }  
    prime[0] = prime[1] = false;  
}

int main() {

    bool prime[1000000];
    sieveOfEratosthenes(prime);

    int n;
    cout << "\nEnter n => " ;
    cin >> n;

    while(n!=-1) {
        if(prime[n])
            cout << n << " is a prime number " << endl;
        else
            cout << n << " is not a prime number " << endl;
        break;
    }

    return 0;
}
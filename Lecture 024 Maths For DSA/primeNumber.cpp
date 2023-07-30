#include<bits/stdc++.h>
using namespace std;

//Time Complexity = O(N^2)
bool isPrime(int n) {
    if(n<=1)    
        return false;
    
    for(int i=2; i<n; i++) {
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}

// TC = O(N^2)
void method2(int n) {
    
    cout << "\nPrime number b/w 1 to " << n << endl;
    for(int i=2; i<=n; i++) {
        int cnt = 0;
        for(int j = 2; j<= i/2; j++){
            if(i%j == 0 ) {
                cnt++;
            }
        }

        if(cnt == 0){
            cout << i << " " << endl;
        }
    }
}

//Time complexity = O(N√N)
void method3(int n) {
    
    cout << "\nPrime number b/w 1 to " << n << endl;
    for(int i=2; i<=n; i++) {
        int cnt = 0;
        for(int j = 2; j<= sqrt(i); j++){
            if(i%j == 0 ) {
                cnt++;
            }
        }

        if(cnt == 0){
            cout << i << " " << endl;
        }
    }
}


//SIEVE OF ERATOSTHENES [by using Taylor Series]
//Time Complexity  -> O( log( log(n) )) 
//Space Complexity -> O(n)
int sieve(int n) {

    vector<bool>prime(n+1, true);
    prime[0] = prime[1] = false;
    int cnt = 0;
    for(int i=2; i<n; i++){
        if(prime[i]){
            cnt++;
        }

        for(int j=2*i ; j<n; j=j+i) {
            prime[j] = false;
        }
    }
    cout << "Total no. of primes are => " << cnt << endl;
}

int main() {
    int n;
    cout << "\nEnter n => " ;
    cin >> n;

    if(isPrime(n)){
        cout << n << " is a prime number " << endl;
    }else {
        cout << n << " is not a prime number " << endl;
    }

    method2(n);
    // method3(n);
    // sieve(n);

    return 0;
}
#include<iostream>
using namespace std;

/*
//this code will exceed the Time Limit Execution;
bool isPrime(int n){

    if(n<=1){
        return 0;
    }

    for(int i=2; i<n; i++){
        if(n%i == 0){

            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cout << "\nEnter the number\n";
    cin>>n;

    if(isPrime(n)){
        cout << n << " is a Prime Number\n\n";
    }else{
        cout << n << " is not a Prime Number\n\n";
    }
}

 */




/* 

//Sieve of eratosthenes:-
//Time complexity will be:- o(n*log(logn)) [by using Taylor Series]
//This code will not exceed TLE
//watch the code of count prime submission on leetcode
#include<vector>

int countPrime(int n){
    cout << "\nEnter the number\n";
    cin>>n;

    vector<bool> prime(true, n+1);
    int count = 0;
    prime[0] = prime[1] = false;

    for(int i=2; i<n; i++){
        if(prime[i]){
            count++;
            for(int j=2*i; j<n; j= j+i){
                prime[j] = 0;
            }
        }
    }
    return count;
    cout << "\nTotal prime no. from 2 to " << n << " will be " << count << endl;
}

 */



//////////////////////////////////////////////////////////////////
////////////          HW : SEGMENTED SIEVE         //////////////
////////////////////////////////////////////////////////////////

/* 

//  GCD/HCF
/////////////////////////////////////////////////////////////////
//////                       FORMULA OF GCD              ////////
//////      gcd(a,b) = gcd(a-b, b) or gcd(a%b, b)        ///////
//////            lcm(a,b)*gcd(a,b) = a*b               ////////
////////////////////////////////////////////////////////////////

// gcd(72, 24) = gcd(48, 24)
//             = gcd(24, 24)
//             = gcd(0, 24)
//             so, 24 will be ans

int gcd(int a, int b){

    if(a==0)
    return b;
    
    if(b==0)
    return a;

    while(a != b){

        if(a>b)
        {
            a = a-b;
        }
        else
        {
            b = b-a;
        }
    }

}

int main(){
    int a, b;
    cout << "\nEnter the value of a and b" << endl;
    cin >> a >> b;

    int ans = gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is: " << ans << endl << endl;
    return 0;
}
 */
//Read coding ninja gcd article attached in description to become the champ in gcd


//read codeforces aticle for properties of modular operator (don't skip this, no matter how much you gain after reading)

//modular Exponentiation:-
// (a+b)%m = a%m + b%m
// a%m - b%m = (a-b)%m
// a%m * b%m = (a*b)%m

//fast Exponentiation:-
//TC of (a^b) will be O(logn)



//Homeworks:-
//(1)Pigeonhole principle
//(2)Catalon number
//(3)Inclusion exclusion principle

//Q. Factorial of no. 212 using %m (m = 10^9+7)

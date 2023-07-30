#include<iostream>
using namespace std;


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

    if(a == 0)
        return b;

    if(b == 0)
        return a;

    while (a != b)
    {
        if( a > b){
            a = a-b;
        }else {
            b = b-a;
        }
    }
    return a;
}

int main() {
    int a, b ;
    cout << "\nEnter a, b (space separated) => ";
    cin >> a >> b;

    cout << "\nGCD of " << a << " & " << b << " => " << gcd(a, b) << endl;

    return 0;
}



//modular Exponentiation:-
// (a+b)%m = a%m + b%m
// a%m - b%m = (a-b)%m
// a%m * b%m = (a*b)%m

//fast Exponentiation:-
//TC of (a^b) will be O(logn)

//read codeforces aticle for properties of modular operator (don't skip this)

//Homeworks:-
//(1)Pigeonhole principle
//(2)Catalan number
//(3)Inclusion exclusion principle

//Q. Factorial of no. 212 using %m (m = 10^9+7)

//https://www.codingninjas.com/codestudio/problems/square-root-integral_893351?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

long long int sqrtInteger(int num) {

    int s = 0;
    int e = num;
    long long int ans = -1;

    while( s <= e ) {
        
        long long int mid = s + ( e - s )/2;
        long long int sqrt = mid * mid;

        if( sqrt == num ) {
            return mid;
        }
        if(sqrt < num) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}


double morePrecision(int num, int precision, int tempSol) {

    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<num; j+=factor) {
            ans = j;
        }
    }
    return ans;
}

int main() {

    int num, precision;
    cout << "\nEnter the number to find the sq. root => ";
    cin >> num;
    
    cout << "\nEnter the precision (an integer) => ";
    cin >> precision;

    long long int tempSol = sqrtInteger(num);
    double result = morePrecision(num, precision, tempSol);

    cout << "\nSquare Root of " << num << " is : " << result  << endl;

    cout << endl;
    return 0;
}
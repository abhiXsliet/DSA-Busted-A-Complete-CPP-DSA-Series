#include<iostream>
#include<math.h>
using namespace std;


// HW: print the binary of a negative number

int main() {
    int n;
    cin>>n;

    float ans= 0;
    int i =0;

    // if we get negative number just make it positive
    if(n<0){
        n = n * (-1);
    }

    while(n!=0){
        int bit = n&1;
        ans = (bit*pow(10,i)+ans);
        n = n >>1;
        i++;

    }
    cout<< "Answer is : "<< ans << endl;
}
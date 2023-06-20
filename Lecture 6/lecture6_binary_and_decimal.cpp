#include<iostream>
#include<math.h>
using namespace std;

/*

//practice more by your own

//only understand the logic we'll do this again 
//Decimal to Binary representation

int main(){

    int n;
    cout << "n = ";
    cin>>n;

    float ans = 0;
    int i = 0;
    while(n != 0){

        int bit = n & 1;

        ans = (bit * pow(10,i) ) + ans;

        n = n >> 1;
        i++;

    }

    cout << "Answer is " << ans << endl;

}

//my way (simplest technique)

int main(){

    int n;
    cout<<"Enter the number to convert into binary: ";
    cin>>n;

    int i = 0;
    float ans = 0;
    while(n != 0){

        int rem = n % 2;
        ans = (rem * pow(10,i)) + ans;

        n = n>>1;
        i += 1;
        
        

    }
    cout << "Answer is " << ans << endl;


}



///////////////////////////////////////////////////
/// HW: print the binary of a negative number ////
/////////////////////////////////////////////////
//Binary to Decimal representation


int main(){

    int n;
    cout << "n = ";
    cin>>n;

    int i = 0, ans = 0;

    while(n != 0){

        int digit = n % 10;
        
        if( digit == 1){
            ans = ans + pow(2,i);
        }

        n = n/10;
        i++;
    }

    cout << ans << endl;

}



//Decimal to Binary for a negative no.



*/

//HW 23:30

int main(){
    int n;
    cin>>n;

    float ans= 0;
    int i =0;

    // if we get negative number just making it positive
    if(n<0){
        n = n * (-1);
    }

    while(n!=0){
        int bit = n&1;
        ans = (bit*pow(10,i)+ans);
        n = n >>1;
        i++;

    }
    cout<< "Answer is : "<< ans<<endl;;
}
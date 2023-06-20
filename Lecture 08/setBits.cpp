#include<iostream>
using namespace std;


//If a & b are two given no.s then return the total set bits in a & b;
//e.g., i/p: a=2, b=3; then their binary will be 10, 11 therefore set-bits in a & b is 3 (since 3 1's are present in their binary format)

int setBits_a(int a){

    int count = 0;
    while(a != 0){
        if(a&1 == 1){
            count++;
        }a = a>>1;
    }
    return count;
}

int setBits_b(int b){

    int count = 0;
    while(b != 0){
        if(b&1 == 1){
            count++;
        }b = b>>1;
    }
    return count;
}

int main(){
    
    int a, b;
    cout << "\nEnter the value of fist and second number (space separated): " ;
    cin>> a >> b;

    int ans1 = setBits_a(a);
    int ans2 = setBits_b(b);
    int ans  = ans1 + ans2;  

    cout << "\nTotal no. of bits are: \n" << ans << endl << endl;


    return 0;
}


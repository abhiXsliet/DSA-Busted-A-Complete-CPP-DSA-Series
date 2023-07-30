#include<iostream>
#include<math.h>
using namespace std;



int main(){

    int n;
    cout<<"Enter the number to convert into binary: ";
    cin>>n;

    float ans = 0;
    int i = 0;
    while(n != 0){

        int bit = n & 1;
        // int bit = n % 2;

        ans = (bit * pow(10,i) ) + ans;

        n = n >> 1;
        i++;

    }
    cout << "Answer is " << ans << endl;

    return 0;
}


#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "n = ";
    cin>>n;
   
    //print number from 1 to n
    int i=1;
    while(i<=n){
        cout << i << " " ;
        i = i+1;
    }

    return 0;
}
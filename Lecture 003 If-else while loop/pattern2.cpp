#include<iostream>
using namespace std;


int main() {
    int n;
    cout << "Please input a number" << endl;
    cin>>n;

    int i = 1;
    
    while(i<=n){

        int j = 1;
        
        while(j<=n){

            cout << i ;
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }

    return 0;
}
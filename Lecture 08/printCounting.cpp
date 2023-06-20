#include<iostream>
using namespace std;

//printing counting 
//function signature
void printCounting(int n){
    for (int i = 1; i<=n ; i++){
        cout << i << " " ;
    }
    cout << endl;
}

int main(){
    int n;
    cout<<"enter a value of n: ";
    cin>>n;
    
    //function call
    printCounting(n);

    return 0;
}

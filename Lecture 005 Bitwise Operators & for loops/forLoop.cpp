#include<iostream>
using namespace std;


int main(){

    int n;
    cout<<"enter the value of n "<<endl;
    cin>>n;

    cout<<"printing the value from 1 to n"<<endl;

    // //for loop
    // for(int i=1; i<=n; i++){
    //     cout<<i<<endl;
    // }

    //other-way of doing above for loop
    int i = 1;
    for( ; ; ){
        if(i<=n){
            cout<< i << endl;
        }
        else{
            break;
        }
        i++;
    }

    //we can do multiple initialisation/condition/increment,decrement at the same time
    for (int a = 0, b = 1, c = 2; a>=0 && b>=1 && c>=2; a--, b--, c--){
        cout<< a << " " << b << " " << c << endl;

    }


    for (int i = 0; i<5; i++){
        for (int j=1; j<=5 ; j++){
            cout<< i << " " << j << endl;

        }
    }

    return 0;
}




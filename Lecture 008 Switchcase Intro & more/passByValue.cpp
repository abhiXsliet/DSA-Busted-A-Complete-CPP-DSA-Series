#include<iostream>
using namespace std;

//PassByValue
//value in first fn remains unaffected if some changes made into the second fn.
void dummy(int n){

    n++;
    cout << "n is " << n <<endl;
    
}

int main(){

    int n;
    cout<<"n = ";
    cin>>n;
    dummy(n);
    cout << "number is : " << n << endl;

    return 0;
}

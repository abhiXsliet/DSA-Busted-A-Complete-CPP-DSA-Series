#include<iostream>
using namespace std;

//even or odd using function
// 1(true) -> even 
// 0(false) -> odd
bool isEven(int a){
    
    if (a&1){  //odd
        return 0;
    }
    return 1; //for even
}

int main(){

    int num;
    cout << "n = ";
    cin >> num;

    if(isEven(num)){
        cout << "Number is even" <<endl;
    }
    else 
        cout << "Number is odd" <<endl;

    return 0;
}

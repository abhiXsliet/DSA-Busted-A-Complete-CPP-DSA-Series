#include<iostream>
using namespace std;

int main(){
    
    int a, b;
    cout<<"Enter the value of a = ";
    cin>>a;

    cout<<"Enter the value of b = ";
    cin>>b;

    char op;
    cout<<"Enter the operation you want to perform"<<endl;
    cin>>op;

    switch (op)
    {
        case '+' : {cout << "sum of the given no. is: "<< a+b <<endl;}
                break;
        
        case '-' : cout << "difference of the given no. is: "<< a-b <<endl;
                break;

        case '*' : cout << "product of the given no. is: "<< a*b << endl;
                break;

        case '/' : cout << "division of the given no. is: "<< a/b <<endl;
                break;

        case '%' : cout << "mod of the given no. is: " << a%b << endl;
                break;
        
        default : cout << "please input a valid operation" << endl;
                break;
    }

    return 0;
}

#include<iostream>
using namespace std;

void sayDigits(int n, string arr[]) {

    //base case
    if(n == 0){
        return ;
    }

    //processing
    int digit = n % 10;
    n = n/10;

    //recursive call
    sayDigits(n, arr);
    
    cout << arr[digit] << " ";

}

int main() {
    
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    int n;
    cout << "\nEnter number = ";
    cin>>n;

    cout << endl;

    sayDigits(n, arr);

    cout << endl << endl;
    return 0;
}


//HW : Draw recursion tree of say digits question and function call stack

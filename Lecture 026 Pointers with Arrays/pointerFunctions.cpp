#include<iostream>
using namespace std;

void print(int *p){
    cout << "printing using print function: " << p << endl;
    cout << "printing using print function: " << *p << endl;
}

void update(int *p){
    //p = p + 1;
    //cout << "Inside Update function: " << p << endl;

    *p = *p + 1;
}

// int arr[] or int *arr both are same because it taking the size of a pointer
int getSum(int *arr, int n){

    //sizeof(arr) = 8-byte expeceted output for 64 bit 
    cout << endl << "Size is: " << sizeof(arr) << endl; 
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i]; //sum += i[arr];
        // arr[i] = *(arr + i);
    }
    return sum;
}

int main(){

    int value = 5;
    int *p = &value;

    // print(p);
    cout << "\nBefore update fn: " << *p << endl;
    update(p);
    cout << "\nAfter update fn: " << *p << endl << endl;

    int arr[6] = {1, 2, 3, 4, 5, 8};
    cout << "Sum is " << getSum(arr, 5) << endl ;

    cout << "Summation is : " << getSum(arr+3, 3) << endl << endl;

    return 0;
}

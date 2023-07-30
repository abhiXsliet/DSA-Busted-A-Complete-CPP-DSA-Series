#include<iostream>
using namespace std;

int getSum(int arr[], int size) {
    //base case
    if(size == 0)
    {
        return 0;
    }
    
    if(size == 1)
    {
        return arr[0];
    }

    int remainingPart = getSum(arr+1, size-1);
    int sum = arr[0] + remainingPart;
    return sum;


}

int main() {
    int n;
    cout << "\nEnter the size of the array = ";
    cin>> n;
    int arr[n];
    
    //taking input in array;
    cout << "\nEnter the elments => ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout << "Sum of the given array will be => " << getSum(arr, n) << endl << endl;

    return 0;
}


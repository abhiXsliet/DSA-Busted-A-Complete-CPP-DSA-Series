#include<iostream>
using namespace std;

//simple way of finding array is sorted or not by comparing alternative elements of the array
bool isSorted(int arr[], int size) {
    for(int i=0; i<size; i++){
        if(arr[i] <= arr[i+1]){
            return true;
        }
        else{
            return false;
        }
    }
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
    int ans = isSorted(arr, n);

    if(ans == 0){
        cout << "Given Array is not sorted" << endl << endl;
    }else
    {
        cout << "Given Array is sorted" << endl << endl;
    }
    

    return 0;
}

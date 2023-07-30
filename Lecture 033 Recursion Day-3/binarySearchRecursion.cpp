#include<iostream>
using namespace std;

//BINARY SEARCH by Recursion
int binarySearch(int* arr, int s, int e, int key){

    print(arr, s, e);
    //base case 
    //1. element not found
    if(s>e){
        return -1;
    }

    int mid = s + (e - s)/2;
    cout << "Value of arr mid is => " << arr[mid] << endl;

    //2. element found
    if(arr[mid] == key){
        return mid;
    }
    
    //processing
    if(arr[mid] < key){
        binarySearch(arr, mid+1, e, key);
    }else{
        binarySearch(arr, s, mid-1, key);
    }
}

void print(int arr[], int s, int e){
    cout << "\nElement in Array => ";
    for(int i=s; i<=e; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main() {
    int n, key;
    cout << "\nEnter the size of the array = ";
    cin>> n;
    int arr[n];

    //taking input in array;
    cout << "\n**Elements should be in sorted order for Binary Search**";
    cout << "\nEnter the elments => ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout << "\nEnter the key to search => ";
    cin>>key;

    int ans = binarySearch(arr, 0, n-1, key);
    cout << "\nElement is present at index " << ans << endl << endl;

    return 0;
}

//HW : Do all the previous binary question lecture(12-15) with recursion

#include<bits/stdc++.h>
using namespace std;

int firstOccurance(int *arr, int n, int key){
    int s = 0;
    int e = n-1;
    int ans = -1;

    while(s<=e){
        int mid = (s + (e - s)/2);
        if(arr[mid] == key){
            ans = mid ;
            e = mid - 1;
        }
        else if(arr[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }        
    }
    return ans;
}

int lastOccurance(int *arr, int n, int key){
    int s = 0; 
    int e = n - 1;
    int ans = -1;
    
    while (s<=e)
    {
        int mid = (s + (e - s)/2);
        if(arr[mid]==key){
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid]<key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }        
    }
    return ans;
}

int findOccurance(int* arr, int n, int target, bool findFirst) {
    int low = 0, high = n-1, result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            if (findFirst) high = mid - 1;
            else low = mid + 1;
        }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    
    return result;
}

void print(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " " ; 
    }
}

void insertEle(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    int n, key;
    cout << "\nEnter the size of the array => ";
    cin >> n;
    int arr[n];

    cout << "\nInsert the elements into array => ";
    insertEle(arr, n);

    cout << "\nArray's Elements : ";
    print(arr, n);
    cout << endl;

    cout << "\nEnter the key element => ";
    cin >> key;

    pair<int, int> p;
    p.first = firstOccurance(arr, n, key);
    p.second = lastOccurance(arr, n, key);
    int totalOcc = p.second - p.first + 1;

    // p.first = findOccurance(arr, n, key, true);
    // p.second = findOccurance(arr, n, key, false);
    // cout << "\nTotal no. of occurance of " << key << " is => " << totalOcc << endl;

    
    cout << "\nLeftmost occurance is => " << p.first << endl;
    cout << "\nRightmost occurance is => " << p.second << endl;
    cout << "\nTotal no. of occurance of " << key << " is => " << totalOcc << endl;


    cout << endl;
    return 0;
}


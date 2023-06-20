//https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

//Time complexity = O(log(n))
int getPivot(int arr[], int n) {
    int s = 0;
    int e = n - 1;

    while(s < e) {
        int mid = s + ( e - s )/2;

        if(arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int binarySearch(int *a, int s, int e, int key) {

    while (s <= e) {
        int mid = s + (e - s)/2;

        if(key < a[mid]) {
            e = mid - 1;
        }else if(key > a[mid]) {
            s = mid + 1;
        }else {
            cout << "\nElement found at index : " << mid << endl;
            return mid;
        }
    }
    return -1;
}

int main() {

    int n, key;
    cout << "\nEnter the size of the array => ";
    cin>>n;
    int arr[n];

    cout << "\nEnter the elements of the array (monotonic sequence) \nsimilar as {3 8 10 17 1} => ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    cout << "\nEnter the key element to search => ";
    cin >> key;

    int pivot = getPivot(arr, n);
    if(key >= arr[pivot] && key <= arr[n-1]) {
        binarySearch(arr, pivot, n-1, key);
    }
    else {
        binarySearch(arr, 0, pivot-1, key);
    }


    cout << endl;
    return 0;
}

//Approach 2 and 3 pending
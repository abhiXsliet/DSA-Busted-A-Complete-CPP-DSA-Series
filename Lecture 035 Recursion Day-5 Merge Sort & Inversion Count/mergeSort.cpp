#include<bits/stdc++.h>
using namespace std;



//Merge sort is the Fastest as compared to all sorting algo.
//Space complexity of merge sort : O(n)
//Time complexity of merge sort : O(nlog(n))
void merge(int arr[], int s, int e) {

    int mid = s + (e - s)/2;

    //length of the first halve
    int len1 = mid - s + 1; 
    //length of the second halve
    int len2 = e - mid; 
    
    //dynamically memory allocation
    int *first = new int [len1];
    int *second = new int [len2];

    //copying values in the first and second array
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    //delete dynamic allocation of memory
    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e) {
    
    //base case - already sorted
    if(s >= e) {
        return;
    }

    int mid = s + (e - s)/2;

    //sort the left halve
    mergeSort(arr, s, mid);

    //sort the right halve
    mergeSort(arr, mid+1, e);

    //merge the both halve
    merge(arr, s, e);
}

void print(int *arr, int n) {

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}

void insertEle(int *a, int n) {

    cout << "\nEnter the elements of the array => ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

int main() {
    int n;
    cout << "\nEnter the size of the array => ";
    cin >> n;
    int arr[n];

    insertEle(arr, n);

    cout << "\nArray before sorting => ";
    print(arr, n);
    cout << endl;

    mergeSort(arr, 0, n-1);
    cout << "\nArray after sorting => ";
    print(arr, n);
    cout << endl;

    cout << endl;
    return 0;
}
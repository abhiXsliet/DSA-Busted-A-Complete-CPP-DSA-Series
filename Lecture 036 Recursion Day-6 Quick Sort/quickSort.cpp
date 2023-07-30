#include<bits/stdc++.h>
using namespace std;

//space complexity = O(n)
    //Time complexity
//Average case = O(nlogn)
//Best case = O(nlogn)
//worst case = O(n^2)

int partation(int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    //handle left and right part
    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }   
    } 
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    //base case
    if(s >= e) {
        return;
    }
    //create partation
    int p = partation(arr, s, e);

    //sort left of partation
    quickSort(arr, s, p-1);
    
    //sort right of partation
    quickSort(arr, p+1, e);
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

    quickSort(arr, 0, n-1);
    cout << "\nArray after sorting => ";
    print(arr, n);
    cout << endl;

    cout << endl;
    return 0;
}


// HW : Wheather Quick sort is a in-place sorting technique?
// HW : check wheather Qucik Sort is a stable algorithm?

//Read GFG article => why Quick Sort is preferred over Merge Sort in sorting arrays?
//Read GFG article => Why Merge Sort is preferred over Merge Sort in Linked list?
//LINK : https://www.geeksforgeeks.org/quick-sort/
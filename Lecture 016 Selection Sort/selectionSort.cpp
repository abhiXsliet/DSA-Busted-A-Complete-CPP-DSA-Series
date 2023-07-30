#include<iostream>
using namespace std;

//Select minimum element and put it at their right position
//USE CASE : For Small size array

//Time Complexity : O(N^2)
//Space Complexity : O(1)
void selectionSort(int *arr, int size) {

    for(int i = 0; i < size-1; i++) {
        int minIndex = i;

        for(int j = i+1; j < size; j++) {

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            
        }
        swap(arr[i], arr[minIndex]);
    }
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

    selectionSort(arr, n);
    cout << "\nArray after sorting => ";
    print(arr, n);
    cout << endl;

    cout << endl;
    return 0;
}




//we can only use this algo on small array/list/vector size wherever we have the limited size (memory usage) constrain; 
//since it's time complexity is o(n^2) in both best and worst.

//stable sorting algorithm maintain a relative order while sorting.
//unstable sorting algorithm doesn't follow any relative order in sorting of elements.

//(HW): Selection Sort is not a stable algorithm because it swaps two adjacent elements

//(HW) flowchart of selection sort:
//[https://1.bp.blogspot.com/-Qt6lwSX0Cck/YM1h0oP2rSI/AAAAAAAAAmI/IZxeFNJ8NQksrm6Rz8xWSUSHoFwUPAlRACLcBGAsYHQ/s526/selection-sort-flowchart-or-flowchart-of-selection-sort.png]


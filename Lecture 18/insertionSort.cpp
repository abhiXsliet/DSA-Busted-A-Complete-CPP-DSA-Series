#include<iostream>
using namespace std;

//USE CASE : When array is small or partially sorted

//Best Case Time Complexity  -> O(N)    -> if array is already sorted
//Worst Case Time Complexity -> O(N^2)  -> if array is in reverse order
//Average Case Time Complexity -> O(N^2) 
//Space Complexity : O(1)

void insertionSort(int *arr, int size) {

    for(int i = 1; i < size; i++) {

        int temp = arr[i];

        int j = i - 1;
        for(; j>=0; j--) {

            if(arr[j] > temp) {
                arr[j+1] = arr[j]; 
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void insertionSort2(int arr[], int size){
    
    for(int i = 0; i<size; i++){
        int temp = arr[i];

        int j = i;
        while(j>0 && arr[j-1] > temp){
            
            arr[j] = arr[j-1]; 
            j--;

        } 
        arr[j] = temp;
    }
   
}

void print(int *arr, int n) {

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}

void insertEle(int *a, int n) {

    cout << "\nEnter the elements of the array (space separated) => ";
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

    insertionSort(arr, n);
    // insertionSort2(arr, n);
    
    cout << "\nArray after sorting => ";
    print(arr, n);
    cout << endl;

    cout << endl;
    return 0;
}

//We use insertion sort because 
//- 1. Adaptable algorithm
//- 2. Stable algorithm
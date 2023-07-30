#include<iostream>
using namespace std;

//USE CASE: To Put the ith largest element to its correct position
//e.g., 1st round - 1st largest element will be placed at the end
//      2nd round - 2nd largest element will be placed at the second last position. so on.......


//Best Case Time Complexity  -> O(N)    -> when array is already sorted
//Worst Case Time Complexity -> O(N^2)  -> when array is reverse sorted
//Average Case Time Complexity -> O(N^2)
//Space Complexity is : O(1)

void bubbleSort(int *arr, int size) {

    for(int i = 0; i < size-1; i++) {
        bool swapping = false;
        for(int j = 0; j < size-i-1; j++) {

            if(arr[j+1] < arr[j]) {
                swap(arr[j], arr[j+1]);
                swapping = true;
            }
        } 

        if(swapping == false) {
            break;
        }
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

    bubbleSort(arr, n);
    cout << "\nArray after sorting => ";
    print(arr, n);
    cout << endl;

    cout << endl;
    return 0;
}
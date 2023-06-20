#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n) {
    
    //base case - already sorted
    if(n == 0 || n == 1){
        return ;
    }

    //1st case solve karlia - largest element end me pahunch jaayega
    for(int i=0; i<n; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    //recursive call
    bubbleSort(arr, n-1);
}

void display(int arr[], int size) {
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "\nEnter the size of the array => ";
    cin>>n;
    int arr[n];
    
    cout << "\nEnter the elements in the array => ";
    for(int i=0; i<n; i++){
        cin >> arr[i] ;
    }

    cout << "\nArray elements before sorting => ";
    display(arr, n);
    
    bubbleSort(arr, n);
    cout << "\nArray elements after sorting => ";
    display(arr, n);

    cout << endl << endl;
}

//Do selection and insertion sort by recursion 









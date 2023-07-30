#include<iostream>
using namespace std;

//SWAPPING ALTERNATE ELEMENTS OF AN ARRAY 
void swapAlternate(int arr[], int size){
    int start = 0;
    for(int i=0; i<size; i++) {

        // swap(arr[start], arr[start+1]);

        int temp = arr[start];
        arr[start] = arr[start+1];
        arr[start+1] = temp;

        start = start+2;
    }
}

//Babbar's Way
void swappingAlternate(int arr[], int size) {

    int i = 0;
    while(arr[i+1] <= size){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        i+=2;
    }

    // for(int i=0; i<size; i+=2){
    //     if(arr[i+1] < size)
    //         swap(arr[i], arr[i+1]);
    // }
}

//SORT 0's and 1's
void sortOne(int arr[], int n){

    int left = 0; int right = n-1;

    while(left < right){
        while(arr[left] == 0 && left < right)
        {
            left++;
        }
        while (arr[right] == 1 && left < right)
        {
            right--;
        }

        //agar yaha pahonch gye ho, 
        //ishka matlab arr[left] == 1 && arr[right] == 0

        if(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }  
    }
}

void insertEle(int arr[], int n){

    cout << "\nEnter the element into the array (space separated) => ";
    for(int i = 0; i<n; i++){
        cin >> arr[i] ;
    }
}

void printArray(int arr[], int n){

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n,i;
    cout << "\nEnter the size of the array => ";
    cin>>n;
    int arr[n];
    
    insertEle(arr,n);
    cout << "\nSwapped alternate => " ;
    swapAlternate(arr,n);
    printArray(arr,n);
    cout << endl;
    
    insertEle(arr,n);
    cout << "\nSwapping Alternate => ";
    swappingAlternate(arr, n);
    printArray(arr,n);
    cout << endl;

    int arr1[8] = {1, 1, 0, 0, 0, 1, 0};
    cout << "\nSorted 0's and 1's => ";
    sortOne(arr1, 8);
    printArray(arr1, 8);

    cout << endl << endl;
    return 0;
}


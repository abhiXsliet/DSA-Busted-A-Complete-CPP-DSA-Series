#include<iostream>
using namespace std;

// //Linear Search using for loop
// bool LinearSearch(int arr[], int size, int key) {    
//     for(int i=0; i<size; i++) {
//         if(key == arr[i]){
//             return true;
//         }
//     }
//     return false;
// }

//Linear search by using Recursion
bool LinearSearch(int* arr, int size, int key){

    print(arr, size);

    //base case
    if(size == 0){
        return 0;
    }

    //processing - solving one step
    if(arr[0] == key){
        return true;
    }else{
        //recursive call
        return LinearSearch(arr+1, size-1, key);

                    //OR
        // bool remainingPart = LinearSearch(arr+1, size-1, key);
        // return remainingPart;
    }
}

void print(int arr[], int n){
    
    cout << "\nSize of array is " << n << endl;

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}


int main() {
    int n, key;
    cout << "\nEnter the size of the array = ";
    cin>> n;
    int arr[n];
    //taking input in array;
    cout << "\nEnter the elments => ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout << "\nEnter the key to search => ";
    cin>>key;

    bool ans = LinearSearch(arr, n, key);

    if(ans == 1){
        cout << "\nElement is present" << endl << endl;
    }else{
        cout << "\nElement is absent " << endl << endl;
    }

    return 0;
}

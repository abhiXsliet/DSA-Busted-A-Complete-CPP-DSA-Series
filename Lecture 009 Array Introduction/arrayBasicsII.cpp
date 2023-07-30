#include<iostream>
#include<climits>
using namespace std;

// If you can change anything inside the update function's array then it will have impact in main function

// update function has the address of the main function declared array
void update(int arr[], int n){

    cout << endl << "Inside the fuction" << endl;

    //updating the array's first element;
    arr[0] = 120;

    //printing the array;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    
    }cout << endl;

    cout << "Going back to the main function" << endl;

}

//Print sum of all elements in an array
int sumArray(int arr[],int n){
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum = sum+arr[i]; //sum += arr[i];
    }
    return sum;
}

//GET MINIMUM
int getMin(int num[], int n){
    int mini = INT_MAX;

    for(int i=0; i<n; i++){
        if(num[i]<mini){
            mini = num[i];
        }
        // mini = min(mini, arr[i]);
    }
    return mini;
}

//GET MAXIMUM
int getMax(int num[], int n){
    int maxi = INT_MIN;

    for(int i=0; i<n; i++){
        if(num[i]>maxi){
            maxi = num[i];
        }
        // maxi = max(maxi, arr[i]);
    }
    return maxi;
}

//LINEAR SEARCH
//Best TC => o(1); when element found at the index 1
//Worst TC => o(n); when element found at the end of the array
bool search(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

void linearSearch(int arr[], int size){
    int x;
    cout << "\nEnter the element to search => " ;
    cin >> x;
    bool temp = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == x){
            cout << "\nElement is present at index => " << i << endl;
            temp = 1;
        }
    }

    if(temp == 0){
        cout << "\nElement is absent" << endl;
    }
}

//REVERSE AN ARRAY
void reverseArray(int arr[], int n){

    cout << "\nReversed array is: \n";
        int start=0; 
        int end=n-1;

    while(start<=end){

        // swap(arr[start], arr[end]);

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void printArray(int arr[], int size ){
    
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    // int arr[3] = {1, 2, 3};

    // update(arr, 3);
    // //printing the array;
    // cout << endl << "printing the main function" << endl;
    // for(int i=0; i<3; i++){
    //     cout << arr[i] << " "; 
    // }

    int n,key;
    cout << "\nEnter the size of the array: "; 
    cin >> n;
    int arr[n];

    cout << "\nEnter the elements of the array: ";
    //taking the input of the elements of array from user
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout << "\nSum of all elements of the array will be: " 
         << sumArray(arr, n) << endl;

    cout << "\nMaximum Value is: " << getMax(arr, n) << endl;
    cout << "\nMinimum value is: " << getMin(arr, n) << endl;

    cout << "\nEnter the elements to search for=> ";
    cin>>key;
    bool found = search(arr, n, key);
    if(found)
        cout << "\nKey is present\n";
    else
        cout << "\nKey is absent\n";

    // linearSearch(arr,n);

    reverseArray(arr,n);
    printArray(arr,n);

    
    return 0;
}



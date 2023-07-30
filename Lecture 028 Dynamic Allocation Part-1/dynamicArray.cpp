#include<bits/stdc++.h>
using namespace std;


int getSum(int *arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){


    char ch = 'q';
    cout << sizeof(ch) << endl;

    char* c = &ch;
    // Always memory allocated 8-bytes for pointer size in 64-byte system
    cout << sizeof(c) << endl; 
    


    //static allocation is when memory is allocated in a stack. Here, memory gets automatically cleared or released;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  dynamic allocation is when a memory is allocated in a heap. 
    //  Here, memory have to be cleared manually by using "delete" keyword 
    //  for array deletion || int* arr = new int[n] :- delete []arr;
    //  for single element || int* i = new int :- delete i;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int n;
    cout << "Enter the value of n = ";
    cin>>n;

    //Memory allocation in Heap
    //variable size array
    int* arr = new int[n];

    //taking input in array
    cout << "Enter the elements => ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = getSum(arr, n);
    cout << "Answer is " << ans << endl << endl;


    //case 1; stack me 4-bytes store krwa k har baar bahar aa jaa rhe hai
    while (true)
    {
        int i = 5;
    }

    //case 2; stack pe 4-bytes store krwa kr aur heap pr int yani 4-bytes store krwa kr bahara aarhe hai lekin heap pr process baar baar continue hi hai
    while(true){
        int* ptr = new int; 
    }

    return 0;
}


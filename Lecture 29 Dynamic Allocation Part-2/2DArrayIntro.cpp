#include<bits/stdc++.h>
using namespace std;

//Bad practice :- 
// int arr[n]
// program will be crashed since the space in the memory is small and you are demanding the much larger memory allocation

//////////////////////////////////////////////////////////
/////////            1-D ARRAY                  //////////
////////       int* arr = new int[n];          ///////////
//////////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//////////            2-D ARRAY               /////////
/////////      int** arr = new int* [n];     //////////
///////////////////////////////////////////////////////

int main() {
        
    int n;
    cout << "Enter n = " ;
    cin>>n;

    // creating 2-D Array
    int** arr = new int* [n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }
    

    // taking input
    cout << "Enter the elements => ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    
    cout << endl;

    // printing output
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }cout << endl;
    
    // delete memory manually
    for(int i=0; i<n; i++) {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
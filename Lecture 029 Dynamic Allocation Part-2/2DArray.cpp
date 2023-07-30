#include<bits/stdc++.h>
using namespace std;

int main(){

    int row, col;
    cout << "Enter the row, col (space seperated) = ";
    cin>>row>>col;

    // creating 2-D Array
    int** arr = new int* [row];
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    // taking the input
    cout << "Enter the elements (as row*col) => ";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    // printing the output
    cout << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }cout << endl;

    // Remember
    // It is important to manually clear the memory after performing operations in the Heap, as it is not automatically cleared like the Stack.

    // releasing memory
    for(int i=0; i<row; i++){
        delete [] arr[i];
    }

    delete[] arr;

   return 0;
}


//HW : Create a Jagged Array dynamic memory

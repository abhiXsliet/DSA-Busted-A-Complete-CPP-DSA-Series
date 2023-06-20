#include<bits/stdc++.h>
using namespace std;

//Bad practice :- 
// int arr[n]
// program will be crashed since the space in the memory is small and you are demanding the much larger memory allocation

////////////////////////////////////////////////////////////
/////////            1-D ARRAY                  ///////////
////////       int* arr = new int[n];          ///////////
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//////////            2-D ARRAY               //////////
/////////      int** arr = new int* [n];     //////////
//////////////////////////////////////////////////////

/* 
int main(){

    
    // int n;
    // cout << "Enter n = " ;
    // cin>>n;

    // //creating 2-D Array
    // int** arr = new int* [n];
    // for(int i=0; i<n; i++){
    //     arr[i] = new int[n];
    // }
    

    // //taking input
    // cout << "Enter the elements => ";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    
    // cout << endl;
    // //taking output
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << arr[i][j] << " ";
    //     }cout << endl;
    // }cout << endl;
    
 



    // int row, col;
    // cout << "Enter the row, col (space seperated) = ";
    // cin>>row>>col;

    // //creating 2-D Array
    // int** arr = new int* [row];
    // for(int i=0; i<row; i++){
    //     arr[i] = new int[col];
    // }

    // //taking the input
    // cout << "Enter the elements (as row*col) => ";
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // //taking the output
    // cout << endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cout << arr[i][j] << " ";
    //     }cout << endl;
    // }cout << endl;

    // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // /// Always keep in mind:- After workdone in Heap one should always clear the memory since it is being cleared manually not automatically like stack /////
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // //releasing memory (17:00)
    // for(int i=0; i<row; i++){
    //     delete [] arr[i];
    // }

    // delete []arr;






   // return 0;

}
 */

//code studio for better understanding : https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118785/offering/1381146

//HW : Create a Jagged Array dynamic memory



int main(){

    int row, col;
    cout << "Enter the row and col (space seperated) => ";
    cin>>row>>col;

    //creating 2-D Array
    int** arr = new int* [row];
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    //
}
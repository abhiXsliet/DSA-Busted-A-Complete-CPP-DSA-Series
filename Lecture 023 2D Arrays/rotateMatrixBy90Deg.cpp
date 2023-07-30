#include<bits/stdc++.h>
using namespace std;

// Rotate the matrix by 90 degrees 
void rotate90(int arr[][3], int row, int col){
  int count = 0;
  int total = row*col;

  int startingRow = 0;
  int startingCol = 0;
  int endingRow = row - 1;
  int endingCol = col - 1;

  while(count<total){
    // print starting col from bottom to top;
    for(int col = 0; col<4; col++){
      for(int index = endingRow; count<total && index>=startingRow; index--){
        cout << arr[index][startingCol] << " ";
        count++;
      }
      startingCol++;
      cout << endl;
    }
  }
}


int main(){
    cout << "\nAfter calling rotate\n";
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
                     
    rotate90(arr, 3, 3);
    
    return 0;
}
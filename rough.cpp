#include <iostream>
using namespace std;


//rotate by 90 degree
void rotate90(int arr[][4], int row, int col){
  int count = 0;
  int total = row*col;

  int startingRow = 0;
  int startingCol = 0;
  int endingRow = row - 1;
  int endingCol = col - 1;

  while(count<total){
    //print starting col from bottom to top;
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
    int arr[5][4], row, col;
    cout << "\nEnter the elements (for row & col)\n";
    for(int row=0; row<5; row++){
        for(int col=0; col<4; col++){
            cin>>arr[row][col];
        }
    }
    cout << "\nPrinting row wise\n" ;
    for(int row=0; row<5; row++){
        for(int col=0; col<4; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }cout << endl;

    cout << "After calling rotate90\n";
    rotate90(arr, 5, 4);
    cout << endl << endl;
    
    return 0;
}
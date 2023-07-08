#include<bits/stdc++.h>
using namespace std;


//Time Complexity => O(n*m) where n = no. of Rows and m = no. of Cols;
//spiral printing starting from col;
int spiralCol(int arr[][4], int row, int col){
    int count = 0; 
    int total = row*col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while(count < total){
        //print starting col;
        for(int index = endingRow; count<total && index>=startingRow; index--){
            cout << arr[index][startingCol] << " ";
            count ++;
        }startingCol++;

        //print starting row;
        for(int index = startingCol; count<total && index<=endingCol; index++){
            cout << arr[startingRow][index] << " ";
            count++;
        }startingRow++;

        //print ending col;
        for(int index = startingRow; count<total && index<=endingRow; index++){
            cout << arr[index][endingCol] << " ";
            count++;
        }endingCol--;

        //print ending row;
        for(int index = endingCol; count<total && index>=startingCol; index--){
            cout << arr[endingRow][index] << " ";
            count++;
        }endingRow--;
    }
}

//SpiralPrint starting from Row
int spiralRow(int arr[][4], int row, int col){
    int count = 0;
    int total = row*col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while(count < total){
        //print starting Row;
        for(int index = startingCol; count<total && index <= endingCol; index++){
            cout << arr[startingRow][index] << " ";
            count++;
        }
        startingRow++;

        //print ending col;
        for(int index = startingRow; count<total && index <= endingRow; index++){
            cout << arr[index][endingCol] << " ";
            count++;
        }
        endingCol--;

        //print ending Row;
        for(int index = endingCol; count<total && index>=startingCol; index--){
            cout << arr[endingRow][index] << " ";
            count++;
        }
        endingRow--;

        //print starting Col;
        for(int index = endingRow; count<total && index>=startingRow; index--){
            cout << arr[index][startingCol] << " ";
            count++;
        }
        startingCol++;
    }
}

int main(){
    int arr[3][4], row, col;
    cout << "\nEnter the elements (for 3-rows & 4-cols)\n";
    for(row=0; row<3; row++){
        for(col=0; col<4; col++){
            cin>>arr[row][col];
        }
    }
    
    cout << "\nPrinting before SpiralPrint\n" ;
    for(row=0; row<3; row++){
        for(col=0; col<4; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }cout << endl;

    cout << "Print after calling SpiralPrint Row wise....\n";
    spiralRow(arr, 3, 4);
    cout << endl ;

    cout << "\nPrint after calling SpiralPrint Col wise....\n";
    spiralCol(arr, 3, 4);
    cout << endl;
    
    cout << endl;
    return 0;
}

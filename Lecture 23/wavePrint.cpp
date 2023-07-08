#include<bits/stdc++.h>
using namespace std;


//Wave Print
//Time complexity => O(n*m) where n = no. of Rows and m = no. of cols
int wavePrint(int arr[][3], int row, int col){
    for(int col=0; col<4; col++){

        if(col&1){
            //odd Index -> bottom to top;
            for(row = 3-1; row>=0; row--){
                cout << arr[row][col] << " ";
            }

        }else{
            //0 or even Index -> top to bottom;
            for(row=0; row<3; row++){
                cout << arr[row][col] << " ";
            }
        }
    }
}

int main(){
    int row, col;
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};

    cout << "\nPrinting before wavePrint\n" ;
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }cout << endl;
    
    cout << "Printing after calling wavePrint\n";
    wavePrint(arr, 3, 3);
    cout << endl;


    cout << endl;
    return 0;
}
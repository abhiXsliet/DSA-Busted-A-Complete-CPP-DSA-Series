#include<bits/stdc++.h>
using namespace std;


//checking the maximum row and their index
int largestRowSum(int arr[][4], int row, int col){

    int maxi = INT_MIN;
    int rowIndex = -1 ;

    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<4; col++){
            sum += arr[row][col];
        }

        if(sum > maxi){
            maxi = sum;
            rowIndex = row;
        }
    }

    cout << "\nThe Maximum sum is : " << maxi;
    return rowIndex;
}

int main(){

    int arr[3][4];

    //taking input row wise;
    cout << "\nEnter the elements\n";
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cin>>arr[row][col];
        }
    }cout << endl;

    //printing
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }

    //checking the maximum sum of the row and their index;

    int ansIndex = largestRowSum(arr, 3, 4);
    cout << "\nMaximum row is at index " << ansIndex << endl << endl;

    return 0;
}



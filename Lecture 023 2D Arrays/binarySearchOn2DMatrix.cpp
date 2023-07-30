#include<bits/stdc++.h>
using namespace std;


//Binary search on 2D Matrix;
//Time complexity will be O(log(n*m));
bool binarySearch(int arr[][4], int row, int col, int target){
    int start = 0;
    int end = row*col - 1;
    int mid = start + (end - start)/2 ;
    
    while(start<=end)
    {
        int element = arr[mid/col][mid%col];

        if(element == target)
        {            
            cout << "\nElement is present at Row Index -> " << mid/col << " and Col Index -> " << mid%col << endl << endl;
            return 1;

        }
        if(element < target)
        {
            start = mid + 1;    
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2; 
    }
    cout << "\nElement is absent\n\n";
    return 0;
    
}

int main(){
    int arr[3][4], row, col, target;
    cout << "\nEnter the elements (for row & col)\n";
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cin>>arr[row][col];
        }
    }cout << endl;

    cout << "\nPrinting before wavePrint\n" ;
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }
    cout << "\nEnter the element to search\n";
    cin>>target;

    binarySearch(arr, 3, 4,target);

    return 0;
}

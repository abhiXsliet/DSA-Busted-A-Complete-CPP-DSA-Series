#include<iostream>
using namespace std;
/* 

int main(){

    //creating 2D Array
    int arr[3][4]; 
    //[]fist place-> row; [] second place-> col;

    //int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    //int arr[3][4] = {{1,11,111, 1111}, {2,22,222,2222}, {3,33,333,3333}};

    // taking input row wise
    // cout << "\nEnter the elements\n";
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cin >> arr[i][j];
    //     }
    // }
    
    //ctrl+k+c for comment and ctrl+k+u for decomment;


    //taking input col wise (you can replace i as row and j as col for better understanding)
    cout << "\nEnter the elements\n";
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            cin>>arr[j][i]; 
        }
    }

    //print
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
*/


/* 

//searching element 
bool isPresent(int arr[][4], int target, int row, int col){
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            if(arr[row][col] == target){
                return 1;
            }
        }
    }
    return 0;
}

//printing row wise sum;
void printRowSum(int arr[][4], int row, int col){
    cout << "Printing sum row wise :- " << endl;
    for(row=0; row<3; row++){
        int sum =0;
        for(col=0; col<4; col++){
            sum += arr[row][col];
        }
        cout << sum << " " ;
    }cout << endl << endl;
}


//printing sum column wise;
void printColSum(int arr[][4], int row, int col){
    cout << "Printing sum column wise :- " << endl;
    for(col=0; col<4; col++){
        int sum = 0;
        for(row=0; row<3; row++){
            sum += arr[row][col];
        }
        cout << sum << " ";
    }cout << endl << endl;
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

    cout << "\nEnter the element to search\n";
    int target;
    cin>>target;

    if(isPresent(arr, target, 3, 4)){
    cout << "\nElement is found\n" << endl;
    }else{
        cout << "\nNot found\n" << endl;
    }

    printRowSum(arr, 3, 4);
    printColSum(arr, 3, 4);

    return 0;
}


 */


/* 
//checking the maximum row and their index
#include<climits>

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


 */

/* 

//Wave Print

int wavePrint(int arr[][4], int row, int col){
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
//Time complexity of the wavePrint will be O(n*m) where n = no. of Rows and m = no. of cols

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

int spiralPrint(int arr[][4], int row, int col){
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
//Time Complexity of spiralPrint will be : O(n*m) where n= no. of Rows and m= no. of Cols;


int main(){
    int arr[3][4], row, col;
    cout << "\nEnter the elements (for row & col)\n";
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cin>>arr[row][col];
        }
    }
    cout << "\nPrinting before wavePrint\n" ;
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }cout << endl;
    
    cout << "Printing after calling wavePrint\n";
    wavePrint(arr, 3, 4);
    cout << endl << endl;

    cout << "Print after calling SpiralPrint\n";
    spiralPrint(arr, 3, 4);
    cout << endl ;

    cout << "\nPrint after calling spiralCol\n";
    spiralCol(arr, 3, 4);
    cout << endl << endl;
    
    return 0;
}

 */


//////////////////////////////////////////////////////////////
////////////            HW(1:00:40)             /////////////
///////       Rotate the matrix by 90 degrees       ////////
///////////////////////////////////////////////////////////

/* 
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


//SpiralPrint starting from Row

int spiralPrint(int arr[][4], int row, int col){
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
//Time Complexity of spiralPrint will be : O(n*m) where n= no. of Rows and m= no. of Cols;



int main(){
    int arr[3][4], row, col;
    cout << "\nEnter the elements (for row & col)\n";
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cin>>arr[row][col];
        }
    }
    cout << "\nPrinting row wise\n" ;
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }cout << endl;

    cout << "\nPrinting col wise\n";
    for(int col=0; col<4; col++){
      for(int row=0; row<3; row++){
        cout << arr[row][col] << " ";
      }cout << endl;
    }

    cout << "\n\nPrint after calling SpiralPrint\n";
    spiralPrint(arr, 3, 4);
    cout << endl ;

    cout << "\nAfter calling rotate\n";
    rotate90(arr, 3, 4);
    cout << endl << endl;
    
    return 0;
}

 */



/* 

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


 */



///////////////////////////////////////////////////////////////////
///////   HW : SOLVE AT LEAST TEN QUESTIONS ON 2D ARRAY    ///////
/////////////////////////////////////////////////////////////////
//LOVE BABBAR 450 QUESTIONS SHEET











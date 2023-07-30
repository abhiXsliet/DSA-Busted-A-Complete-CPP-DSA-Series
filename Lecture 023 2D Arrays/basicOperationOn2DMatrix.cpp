#include<iostream>
using namespace std;


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


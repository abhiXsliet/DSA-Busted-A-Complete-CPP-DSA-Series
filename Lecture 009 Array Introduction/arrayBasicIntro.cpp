#include<iostream>
#include<array>
using namespace std;

//calling array help of function
void printArray(int arr[], int size){

    cout << "printing the array " << endl;
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i] << " ";
    }
    cout << "Printing DONE " << endl;
}

int main(){
    //declare
    int number[15] = {2,7};

    //access the array
    cout << "value at 14th-index " << number[14] << endl; // garbage value
    // we can't print the index 20 because above array is of 15 length

    int second[3] = {5, 7, 11};
    //accessing the element
    cout << "value at 2nd-index: " << second[2] << endl;

    int third[15] = {2,7};
    int n = 15;
    for(int i=0; i<n; i++){
        cout << third[i] << " ";
    }
    int thirdSize = sizeof(third)/sizeof(int);
    cout << "\nSize of third arr. is => " << thirdSize << endl;
    //IMPORTANT -> It'll give the size as 15, since the length of the array(third) is 15
    // But it is not possible to find the actual length of the array i.e, 2 {2,7}. We have to explicitly pass this as an argument into the function
    
    //initialising only zero index with 0 and all rest indexes with 0's too
    int fourth[10] = {0};
    n = 10;
    printArray(fourth, 10);

    int fifth[10] = {1};
    n = 10;
    printArray(fifth, 10);


    // to initialize array with any value; here initializing '1'
    int arrayX[20];
    fill_n(arrayX,20,1);
    printArray(arrayX, 20);

    //also use .fill but print function call does not work here
    array<int, 20>newArr;
    newArr.fill(1);
    for(int i=0; i<20; i++)
        cout << newArr[i] << " ";

    char ch[5] = {'a', 'b', 'c', 'd', 'r'};
    for(int i=0; i<5; i++){
        cout << ch[i] << " ";
    }
    cout <<"printing the char array: " << ch[3] << endl;

    double firstDouble[5];
    bool firstBool[6];
    float firstFloat[8];

    cout << "Everything is fine" << endl;
    cout << endl;
}


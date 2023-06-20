#include<iostream>
using namespace std;

void print(int *p){
    cout << "printing using print function: " << p << endl;
    cout << "printing using print function: " << *p << endl;
}

void update(int *p){
    //p = p + 1;
    //cout << "Inside Update function: " << p << endl;

    *p = *p + 1;
}

int getSum(int *arr, int n){
    //int arr[] or int *arr both are same because it taking the size of a pointer

    cout << endl << "Size is: " << sizeof(arr) << endl; //sizeof(arr) = 8 expeceted output
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i]; //sum += i[arr];
        // arr[i] = *(arr + i);
    }
    return sum;
}
int main(){
/* 
    int arr[10] = {23, 122, 41, 67};

    cout << "Address of first memory block is: " << arr << endl;
    cout << arr[0] << endl;
    cout << "Address of first memory block is: " << &arr[0] << endl;

    cout << "4th => " << *arr << endl;
    cout << "5th => " << *arr + 1 << endl;
    cout << "6th => " << *(arr + 1) << endl;
    cout << "7th => " << *(arr) + 1 << endl;
    cout << "8th => " << arr[2] << endl;
    cout << "9th => " << *(arr+2) << endl;

    int i = 3; 
    cout << i[arr] << endl;
    cout << arr[i] << endl;


 */

    /////////////////////////////////////////
    //////    arr[i] = *(arr + i)      /////
    /////     i[arr] = *(i + arr)     /////
    //////////////////////////////////////
/* 
    int temp[10] = {1, 3, 5};
    cout << sizeof(temp) << endl;
    cout << "1st => " << sizeof(*temp) << endl;
    cout << "2nd => " << sizeof(&temp) << endl; //8-byte

    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl; //8-byte
    cout << sizeof(*ptr)<< endl;
    cout << sizeof(&ptr)<< endl; //8-byte

    cout << endl << endl; 

*/

/* 
    int a[20] = {1, 2, 3, 5};
    cout << " -> " << &a[0] << endl;
    cout << &a << endl;
    cout << a << endl;

    int *p = &a[0];
    cout << p << endl;
    cout << *p << endl;
    cout << " -> " << &p << endl;

    cout << endl << endl;

 */

/* 
    //ERROR
    //arr = arr + 1;

    int *ptr = arr[0];
    cout << ptr << endl;
    ptr = ptr + 1;
    cout << ptr << endl;

 */

/* 
    //CHARACTER & ARRAY DIFFERENCE
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    cout << arr << endl;

    //Attention here
    cout << ch << endl;

    char *c = &ch[0];
    //print entire string
    cout << c << endl;]

 */


/* 
    char temp = 'z';
    char *p = &temp; //watch at 43:00 something important

    cout << p << endl;

 */


/* 
    //FUNCTIONS:-

    int value = 5;
    int *p = &value;

    // print(p);
    cout << "\nBefore update fn: " << *p << endl;
    update(p);
    cout << "\nAfter update fn: " << *p << endl << endl;

 



    int arr[6] = {1, 2, 3, 4, 5, 8};
    cout << "Sum is " << getSum(arr, 5) << endl ;

    cout << "Summation is : " << getSum(arr+3, 3) << endl << endl;

    return 0;
*/
}


//read the documentation from the code studio on pointers to become the champ : https://www.codingninjas.com/codestudio/guided-paths/pointers


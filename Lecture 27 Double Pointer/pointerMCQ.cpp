#include<iostream>
using namespace std;

void update(int *p){
    *p = (*p) * 2;
}

void fun (int arr[]){
    cout << arr[0] << " ";
}

void square(int *p){
    int a = 70;
    p = &a;
    *p = (*p) * (*p);
    cout << "Inside Square fn : " << a << endl;
}

void increment(int **p){
    ++(**p);
}

int main(){

/*     
    int first = 8;
    int second = 18;
    int *ptr = &second;
    *ptr = 9;
    cout << first << " " << second << endl;
*/


/* 
    int first = 6;
    int *p = &first;
    int *q = p;
    (*q)++;
    cout << first << endl;
*/


/* 
    int first = 8;
    int *p = &first;
    cout << (*p)++ << " ";
    cout << first << endl;
*/


/* 
    int *p = 0;
    int first = 110;
    *p = first; //ERROR: Segmentation fault since here is a null pointer. If you are writting int *p = 0 then you should be doing like [p = &i] not [*p = i]
    cout << *p << endl;
*/
 

/* 
    int *p = 0;
    int first = 110;
    p = &first;
    cout << *p << endl;
*/


/* 
    int first = 8; 
    int second = 11;
    int *third = &second;
    first = *third;
    *third = *third + 2;
    cout << first << " " << second << endl;
*/


/* 
    float f = 12.5;
    float p = 21.5;
    float* ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout << *ptr << " " << f << " " << p << endl;
*/


/* 
    int arr[5];
    int *ptr;
    cout << sizeof(arr) << " " << sizeof(ptr) << endl; //expected 20 8 as soln.
*/ 


/* 
    int arr[] = {11, 21, 13, 14};
    cout << *(arr) << " " << *(arr+1) << endl;
*/ 


/* 
    int arr[6] = {11, 12, 21};
    cout << arr << " " << &arr << arr[0] << endl;
*/


/* 
    int arr[6] = {11, 21, 13};
    cout << (arr + 1) << endl;
*/


/* 
    int arr[6] = {11, 21, 31};
    int *p = arr;
    cout << p[2] << endl; //p[2] = *(p+2)
*/


/* 
    int arr[] = {11, 12, 13, 14, 15};
    cout << *(arr) << " " << *(arr + 3);
*/


/* 
    int arr[] = {11, 21, 31, 41};
    int *ptr = arr++;   //ERROR : We can't update the array in a symbol table. we can only update a pointer
    cout << *ptr << endl;
*/ 


/* 
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl;
*/


/* 
    char arr[] = "abcde";
    char* p = &arr[0];
    cout << p << endl; //here, the whole string will be printed since it's functioning is not similar to the integer
*/


/* 
    char arr[] = "abcde";
    char *p = &arr[0];
    p++;
    cout << p << endl;
*/


/*     char str[] = "babbar";
    char *p = str;
    cout << str[0] << " " << p[0] << endl;
*/


/* 
    int i = 10;
    update(&i);
    cout << i << endl;
*/


/* 
    int arr[] = {11, 12, 13, 14};
    fun(arr + 1);
    cout << arr[0] << endl;
*/


/* 
    int a = 70;
    square(&a);
    cout << a << endl;
*/


/* 
    int first = 10;
    int *p = &first;
    int **q = &p;
    int second = 20;
    *q = &second;
    (*p)++;
    cout << first << " " << second << endl;
*/


/* 
    int first = 110;
    int *p = &first;
    int **q = &p;
    int second = (**q)++ + 9;
    cout << first << " " << second << endl;
*/


/* 
    int first = 100;
    int *p = &first;
    int **q = &p;
    int second = ++(**q);
    int *r = *q;
    ++(*r);
    cout << first << " " << second << endl;
*/


/* 
    int num = 110;
    int *ptr = &num ;
    increment(&ptr);
    cout << num << endl;
*/

    // Read code studio documentation as a homework

    return 0;
}
#include<iostream>
using namespace std;


//by using #define we can create macros
//macro is a piece of code in a program that is replaced by the value of macro. It does not take any extra storage like variables.
//whenever a macro is encountered by the compiler, it replaces the name with the definitions of the marcro. Macro definitions need not to be terminated by the semi-colon.
//gfg article about macro: https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/


//GLOBAL VARIABLES (scope is global) :-> One can share the same memory block with different names (like reference variables) and many fn. can access that memory block 
//BAD Practice sharing varibles with the help of global variables because anyone can change the variable values.
//When you want to share a variable then use the concept of reference variable. 
/* 

int score = 15;

void a(int& i){
    cout << score << " in a" << endl;
    score++;
    char = 'a';
    cout << i << endl;
}

void b(int& i){
    cout << score << " in b" << endl;
    cout << i << endl;
}

int main(){
    cout << score << " in main" << endl;
    int i = 5;
    a(i);
}

 */


/* 

//Inline Functions: are used to reduce the function calls overhead
//faayada :- >no memory usage
//           >no function call
//           >no performance hit like it was hitting during fn. call
//           >inline works on single line, may or may not work on 2/3 line, will not work on >3 line

inline int getMax(int a , int b) {
    
    return (a>b) ? a : b;

}

int main(){

    int a = 1; 
    int b = 2;
    int ans = 0;

    ans = getMax(a,b); //code execute hone ke pahle getMax will be replaced by (a>b)?a:b; since it is an inline (inline benefits: no extra memory allocation, no fn. call, no performance hit because no fn. get called)
    cout << ans << endl;

    a = a + 3;
    b = b + 1;

    ans = getMax(a, b);
    cout << ans << endl;

    return 0;
}


 */




/* 

//Default argument :-> value dena hai to deh de nhi to equal wala value use kr lunga
//koi value de signature func() me to wo use kr lunga agar nhi dega to default wala use ho jayega
//Always works from the right most argument/parameter to left the most

void print(int arr[], int n = 0, int start = 1) {

    for(int i = start; i<n; i++){
        cout << arr[i] << endl;
    }
}

int main(){

    int arr[5] = {1, 4, 7, 8, 9};
    int size = 5;

    print(arr, size);
    cout << endl ;
    print(arr, size, 2);

    return 0;
}

 */

//read the documentation on constant variable from the code studio mentioned in the description
//https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118785/offering/1381146


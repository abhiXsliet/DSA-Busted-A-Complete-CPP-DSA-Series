#include<bits/stdc++.h>
using namespace std;

//pass by value :- Here we allocated the separate memory to the newly created variable because it creates a copy of the data to the newly created variable

//when we use a reference variable in a function then it is called as pass by reference.
//In Pass by reference no new memeory is allocated to the newly created variable and the newly created variable points the same memory location  (simply, memory toh allocate hui padi hai variable ko bas ek naya naam de rha hu (same memory but different name))
void update2 (int& n){ //Here, 'int& n' is a reference variable
    n++;
}

void update1(int n){
    n++;
}

//BAD PRACTICE (18:00)
/* 
int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
    //we can't call the local variable outside the braces
} 

int* func(int n){
    int* ptr = &n;
    return ptr;
    //Here we can't call the local variable 'ptr' outside the braces
}
*/

int getSum(int *arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
/*     
    int i = 5;

    //create a ref variable

    int& j = i;

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    cout << j << endl;
 */

/* 
    int x = 5;
    cout << "Before " << x << endl;
    update1(x);
    cout << "After " << x << endl << endl;


    int n = 5;
    cout << "Before " << n << endl;
    update2(n);
    cout << "After " << n << endl;

 */

    char ch = 'q';
    cout << sizeof(ch) << endl;

    char* c = &ch;
    cout << sizeof(c) << endl; //Always expected 8-bytes for pointer size in 64-byte system
    


    //static allocation is when memory is allocated in a stack. Here, memory gets automatically cleared or released;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // dynamic allocation is when a memory is allocated in a heap. Here, memory should be cleared manually by using "delete" keyword 
    // for array deletion || int* arr = new int[n] :- delete []arr;
    // for single element || int* i = new int :-  delete i;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int n;
    cout << "Enter the value of n = ";
    cin>>n;

    //Memory allocation in Heap
    //variable size array
    int* arr = new int[n];

    //taking input in array
    cout << "Enter the elements => ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = getSum(arr, n);
    cout << "Answer is " << ans << endl << endl;

    //Difference b/w Static and Dynamic Memory allocation at (39:00)

/* 
//case 1; stack me 4-bytes store krwa k har baar bahar aa jaa rhe hai
    while (true)
    {
        int i = 5;
    }

//case 2; stack pe 4-bytes store krwa kr aur heap pr int yani 4-bytes store krwa kr bahara aarhe hai lekin heap pr process baar baar continue hi hai
    while(true){
        int* ptr = new int; 
    }

    return 0;
 */

}

//read documentation of code studio from the description
//https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118785/offering/1381146
//void pointer?
//address typcasting?

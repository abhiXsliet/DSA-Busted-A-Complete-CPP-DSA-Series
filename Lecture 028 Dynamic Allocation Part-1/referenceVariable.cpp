#include<bits/stdc++.h>
using namespace std;

// Pass by value: In this case, a separate memory allocation is made for the newly created variable as it creates a copy of the data for the newly created variable.

// When we use a reference variable in a function then it is called as pass by reference.
// In Pass by reference no new memeory is allocated to the newly created variable and the newly created variable points the same memory location (same memory but different name)

void update2 (int& n){ //Here, 'int& n' is a reference variable
    n++;
}

void update1(int n){
    n++;
}

//BAD PRACTICE (18:00)

int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
    //we can't call the local variable outside the braces
} 

int* fun(int n){
    int* ptr = &n;
    return ptr;
    //Here we can't call the local variable 'ptr' outside the braces
}

int main() {
        
    int i = 5;

    //create a ref variable
    int& j = i;

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    cout << j << endl;



    int x = 5;
    cout << "Before " << x << endl;
    update1(x);
    cout << "After " << x << endl << endl;


    int n = 5;
    cout << "Before " << n << endl;
    update2(n);
    cout << "After " << n << endl;

    fun(n);

    return 0;
}
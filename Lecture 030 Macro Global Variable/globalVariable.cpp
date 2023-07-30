#include<iostream>
using namespace std;


//GLOBAL VARIABLES (scope is global) :-> 
// One can share the same memory block with different names (like reference variables) and many fn. can access that memory block 
// BAD Practice -> sharing varibles with the help of global variables because anyone can change the variable values.
// When you want to share a variable then use the concept of reference variable. 


int score = 15;

void a(int& i){
    cout << score << " in a" << endl;
    score++;
    char ch = 'a';
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

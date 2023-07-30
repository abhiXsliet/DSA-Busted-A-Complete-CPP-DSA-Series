#include<bits/stdc++.h>
using namespace std;

//Recursion :-> (Book says) When a function calls itself directly or indirectly 

//Recursive Relation :->  f(n) = 2 * f(n-1)  
//When a big problem solution depends upon the smaller problem of same type for its solution

//In Recursioin : 1. Base case -> mandatory to write and return. Also, it requires to avoid the segmentation fault since it don't know when to stop, so stack become full & overflow can occurs that's why segmentation fault can happen.
//              : 2. Recursive relation -> mandatory to write this too.


//Recursive Relation for factorial :->  f(n) = n * f(n-1) 


int factorial(int n) {

    //1. Base case statement -> why? -> To avoid Segmentation fault -> stack overflow
    if(n == 0){
        return 1;
    }

    //2. returning recursive relation statement
    int smallerProblem = factorial(n-1);
    int biggerProblem = n * smallerProblem;

    return biggerProblem;

    return n * factorial(n-1);
}


//Recursive Relation for pow(2, n):->  f(n) = 2 * f(n-1)  
int power(int n) {

    //base case
    if(n == 0){
        return 1;
    }

    //Recursive Relation
    int smallerProblem = power(n - 1);    
    int biggerProblem = 2 * smallerProblem;

    return biggerProblem;
    //return 2*power(n-1);

    return 2*power(n-1);
}


//Print counting
void print(int n) {

    //Base case
    if(n == 0) {
        return ;
    }

    //cout << n << endl; //Here, it a Tail recursion 

    //Recursive Relation
    print(n-1);

    cout << n << endl;  //Here, it is a Head Recursion 

}

int main() {

    int n;
    cout << "\nEnter n = ";
    cin>>n;

    int ans = factorial(n);
    cout << "factorial of " << n << " will be => " << ans << endl << endl;

    int ansP = power(n);
    cout << "2 to the power " << n << " will be => " << ansP << endl << endl;

    print(n);

    cout << endl;
    return 0;
} 




//RECURSION TREE    
// func(){ Base case -> Processing -> Recursive Rel } || func(){Base case -> Recursive Rel. -> Processing }
// Tail Recursion : A function in which Recursive Relation comes in the end of processing
// Head Recursion : A function in which Recursive Relation comes in the above of processing


//Read coding ninja documentation for better understanding of Recursion
//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380913







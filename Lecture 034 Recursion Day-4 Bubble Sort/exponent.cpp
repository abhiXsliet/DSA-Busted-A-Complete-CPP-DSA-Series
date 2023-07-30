#include<iostream>
using namespace std;

//optimzed code with the help of recursion
//Result of a^b with the help of Recursion 

int power(int a, int b) {

    //base case
    if(b == 0){
        return 1;
    }

    if(b == 1){
        return a;
    }

    //Recursive call
    int ans = power(a, b/2);

    if(b%2 == 0)
    {
        //if b is even
        return ans * ans;
    }
    else
    {   
        //if b is odd
        return a * ans * ans;
    }
}

int main() {
    int a; int b;
    cout << "\nEnter the value of a => ";
    cin>>a;
    cout << "\nEnter the value of b => ";
    cin>>b;

/*     //not optimized sol. 
    //for e.g., consider obtaining the ans of 2^1024; in this case one have to traverse the loop 1024 times
    int ans = 1;
    for(int i = 0; i<b; i++){
        ans = ans * a;
    }
    cout << "\na^b => " << ans << endl << endl;
 */

    cout << "\nAnswer of a^b is => " << power(a, b) << endl << endl;


    return 0;
}

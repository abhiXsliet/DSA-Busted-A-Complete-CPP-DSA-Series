#include<iostream>
using namespace std;

int climbStairs(int n) {

    //base case;
    if(n < 0)
        return 0;

    if(n==0) 
        return 1;

    //recursive call
    return climbStairs(n-1) + climbStairs(n-2);

}

int main() {

    int n;
    cout << "\nEnter n = ";
    cin>>n;

    int ans = climbStairs(n);
    cout << "ways to climb " << n << "th stair will be => " << ans << endl << endl;

    return 0; 
}

//https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156



#include<bits/stdc++.h>
using namespace std;

//Time Complexity will be O(N)
//Space Complexity will be O(N) + O(N) = O(N)
int fib(int n, vector<int>& dp)
{
    //base case
    if(n == 0 || n == 1)
    {
        return n;
    }

    //step-3
    if(dp[n] != -1) {
        return dp[n];
    }

    //step-2 -> store ans
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}


int main() {
    int n;
    cin >> n;

    //step-1 -> Creation of 1D Array
    vector<int> dp(n+1, -1);

    cout << fib(n, dp) << endl;

    return 0;
}
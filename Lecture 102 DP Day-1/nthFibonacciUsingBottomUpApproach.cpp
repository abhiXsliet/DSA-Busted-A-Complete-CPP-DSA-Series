//https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156
//Time Complexity will be O(N)
//Space Complexity will be O(N)


#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    //step-1 -> Creation of 1D Array
    vector<int> dp(n+1);

    //step-2
    dp[1] = 1;
    dp[0] = 0;

    //step-3
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


int main() {
    int n;
    cin >> n;

    int ans = fib(n);
    cout << ans << endl;

    return 0;
}
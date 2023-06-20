//https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208


#include <bits/stdc++.h> 
#define MOD 1000000007
using namespace std;

int add(int a, int b) {
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b) {
    return ((a%MOD)*1LL * (b%MOD))%MOD;
}

//Time Complexity is expontential for this solution
int solveRec(int n, int k) {
    //base case
    if(n == 1)
        return k;
    if(n == 2)
        return add(k, mul(k,(k-1)));
    
    int ans = add( mul(solveRec(n-2, k), (k-1)), mul(solveRec(n-1, k), (k-1)) );
    return ans;
}

//Time Complexity => O(N)
//Space Complexity => O(N)
int solveMem(int n, int k, vector<int>& dp) {
    //base case
    if(n == 1)
        return k;
    if(n == 2)
        return add(k, mul(k, k-1));

    //step-3
    if(dp[n] != -1)
        return dp[n];

    //step-2
    dp[n] = add( mul(solveMem(n-2, k, dp), k-1), mul(solveMem(n-1, k, dp), k-1) );
    return dp[n];
}

//Time Complexity => O(N)
//Space Complexity => O(N) + O(N) => Recursion Depth + DP-array space
int solveTab(int n, int k) {
    //step-1
    vector<int>dp(n+1, 0);
    //step-2
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));
    //step-3
    for(int i=3; i<=n; i++) {
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    return dp[n];
}

//Time Complexity => O(N)
//Space Complexity => O(1)
int solveSO(int n, int k) {
    //step-1
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));
    //step-2
    for(int i=3; i<=n; i++) {
        int ans = add(mul(prev1, k-1), mul(prev2, k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    //step-3
    return prev1;
}

int numberOfWays(int n, int k) {
    //Recursion
    // return solveRec(n, k);

    //Memoization+Recursion -> Top-Down DP
    //step-1
    // vector<int> dp(n+1, -1);
    // return solveMem(n, k, dp);


    //Tabulation -> Bottom-Up DP
    // return solveTab(n, k);

    //Space Optimisation
    return solveSO(n, k);
}



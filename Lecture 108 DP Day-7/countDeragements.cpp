//https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#define MOD 1000000007
#include<vector>
using namespace std;

//Time Complexity will be Exponential for this solution
long long int solveRec(int n) {
    //base case
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    int ans = ( ((n-1)%MOD) * ( (solveRec(n-2)%MOD) + (solveRec(n-1)%MOD) )%MOD );

    return ans;
}

//Time Complexity => O(N)
//Space Complexity => O(N)+O(N) -> for recursion depth + dp-array
long long int solveMem(int n, vector<long long int>& dp) {
    //base case
    if(n == 1) 
        return 0;

    if(n == 2)
        return 1;
    //step-3
    if(dp[n] != -1)
        return dp[n];
    //step-2
    dp[n] = ( ((n-1)%MOD)* ((solveMem(n-2, dp)%MOD) + (solveMem(n-1, dp)%MOD))%MOD );
    return dp[n];
}

//Time Complexity => O(N)
//Space Complexity => O(N)
long long int solveTab(int n) {
    //step-1
    vector<long long int>dp(n+1, 0);
    //step-2
    dp[1] = 0;
    dp[2] = 1;
    //step-3
    for(int i=3; i<=n; i++) {
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum = (first+second)%MOD;

        long long int ans = ( (i-1)* (sum) )%MOD;
        dp[i] = ans;
    }
    return dp[n];
}

//Time Complexity => O(N)
//Space Complexity => O(1)
long long int solveSpaceOpt(int n) {
    long long int prev1 = 1;
    long long int prev2 = 0;

    for(int i=3; i<=n; i++) {
        long long int first = prev1%MOD;
        long long int second = prev2%MOD;
        long long int sum = (first+second)%MOD;

        long long int ans = ((i-1)*(sum))%MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


long long int countDerangements(int n) {
    
    // //Recursive 
    // return solveRec(n);

    // //Memoization+Recursion
        //step-1
    // vector<long long int>dp(n+1, -1);
    // return solveMem(n, dp);

    // //Tabulation
    // return solveTab(n);

    //Space Optimisation
    return solveSpaceOpt(n);

}
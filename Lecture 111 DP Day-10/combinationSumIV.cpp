//https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252

#include <bits/stdc++.h>
using namespace std;

//Time complexity is exponential for this recursive solution
int solveRec(vector<int>& num, int tar) {
    //base case
    if(tar == 0) 
        return 1;
    if(tar < 0)
        return 0;

    int ans = 0;
    for(int i=0; i<num.size(); i++) {
        ans += solveRec(num, tar-num[i]);
    }
    return ans;
}

//Time complexity => O(N) where N = target value
//Space Complexity => O(N)
int solveMem(vector<int>& num, int tar, vector<int>& dp) {
    //base case
    if(tar == 0)
        return 1;
    if(tar < 0)
        return 0;
    
    if(dp[tar] != -1) 
        return dp[tar];

    int ans = 0;
    for(int i=0; i<num.size(); i++) {
        ans += solveMem(num, tar-num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

//Time Complexity => O(N*M) Where N = target Value, M = size of num-array
//Space Complexity => O(N) where N = target value
int solveTab(vector<int>& num, int tar) {
    //step-1:
    vector<int> dp(tar+1, 0);

    //step-2: analyse the base case
    dp[0] = 1;

    //step-3: 
    //traversing on target from 1 to tar
    for(int i=1; i<=tar; i++) {
        //traversing on num vector
        for(int j=0; j<num.size(); j++) {
            if(i-num[j] >= 0)
                dp[i] += dp[i-num[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // return solveRec(num, tar);

    // //Recursion + Memoization
    // vector<int> dp(tar+1, -1);
    // return solveMem(num, tar, dp);

    return solveTab(num, tar);
}
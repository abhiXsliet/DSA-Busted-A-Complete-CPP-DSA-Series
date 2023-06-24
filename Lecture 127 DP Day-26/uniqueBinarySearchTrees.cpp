//https://leetcode.com/problems/unique-binary-search-trees/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(exponential) -> O(2^n)
    //Space Complexity => O(n) -> Recursive Call Stack
    int solveRec(int n) {
        //base case
        if(n<=1)
            return 1;
        
        int ans = 0;
        //i-> root node
        for(int i=1; i<=n; i++) {
            ans+=solveRec(i-1)*solveRec(n-i);
        }
        return ans;
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n)
    int solveMem(int n, vector<int>& dp) {
        //base case
        if(n<=1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];

        int ans = 0;
        //i-> root node
        for(int i=1; i<=n; i++) {
            ans+=solveMem(i-1, dp)*solveMem(n-i, dp);
        }
        return dp[n] = ans;
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n)
    int solveTab(int n) {
        vector<int>dp(n+1, 0);

        //after analyzing base case
        dp[0] = dp[1] = 1;

        //node-> number of nodes
        for(int node=2; node<=n; node++) {
            //j-> root node
            for(int j=1; j<=node; j++) {
                dp[node] += dp[j-1]*dp[node-j];
            }
        }
        return dp[n];
    }

    //Time Complexity => O(n)
    //Space Complexity => O(1)
    long long int catalanNum(long long int n) {
        if(n <= 1)
            return 1;

        long long int ans = 1;
        for(long long int i=1; i<=n; i++) {
            ans = ans * (2*(2*i-1)) / (i+1);
        }
        return ans;
    }

public:
    int numTrees(int n) {
        // //Recursive 
        // return solveRec(n);
        
        // //Recursion+Memoization
        // vector<int> dp(n+1, -1);
        // return solveMem(n, dp);    

        // //Tabulation
        // return solveTab(n);  

        return catalanNum(n);
    }
};
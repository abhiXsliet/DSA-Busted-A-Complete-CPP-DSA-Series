//https://leetcode.com/problems/guess-number-higher-or-lower-ii/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    //Time Complexity => O(n!)
    //Space Complexity => O(n)
    int solveRec(int start, int end) {
        //base case
        if(start >= end)
            return 0;
        
        int maxi = INT_MAX;
        for(int i=start; i<=end; i++) {
            maxi = min( maxi, i+max(solveRec(start, i-1), solveRec(i+1, end)) );
        }
        return maxi;
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveMem(int start, int end, vector<vector<int>>& dp) {
        //base case
        if(start >= end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int maxi = INT_MAX;
        for(int i=start; i<=end; i++) {
            maxi = min( maxi, i+max(solveMem(start, i-1, dp), solveMem(i+1, end, dp)) );
        }
        return dp[start][end] = maxi;
    }


    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveTab(int n) {
        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));

        for(int start=n; start>=1; start--) {
            for(int end=start; end<=n; end++) {
                if(start == end) continue;
                else {
                    int maxi = INT_MAX;
                    for(int i=start; i<=end; i++) {
                        maxi = min( maxi, i+max(dp[start][i-1], dp[i+1][end]) );
                    }
                    dp[start][end] = maxi;
                }
            }
        }
        return dp[1][n];
    }
public:
    int getMoneyAmount(int n) {
        // //Recursion
        // return solveRec(1, n);

        // //Recursion + Memoization
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveMem(1, n, dp);

        //Tabulation
        return solveTab(n);
    }
};
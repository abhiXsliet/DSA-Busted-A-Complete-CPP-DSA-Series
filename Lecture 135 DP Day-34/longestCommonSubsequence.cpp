// https://leetcode.com/problems/longest-common-subsequence/



#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(2^(n+m))
    //Space Complexity => O(n+m) -> recursive call stack
    int solveRec(string& text1, string& text2, int i, int j) {
        int n = text1.length();
        int m = text2.length();
        //base case
        if(i >= n || j >= m)
            return 0;
        
        if(text1[i] == text2[j]) 
            return 1+solveRec(text1, text2, i+1, j+1);
        else 
            return max(solveRec(text1, text2, i, j+1), solveRec(text1, text2, i+1, j));
    }

    //Time Complexity => O(n*m)
    //Space Complexity => O(n*m)
    int solveMem(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        int n = text1.length();
        int m = text2.length();
        //base case
        if(i >= n || j >= m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j]) 
            return 1+solveMem(text1, text2, i+1, j+1, dp);
        else 
            return dp[i][j] = max(solveMem(text1, text2, i, j+1, dp), solveMem(text1, text2, i+1, j, dp));
    }

    //Time Complexity => O(n*m)
    //Space Complexity => O(n*m)
    int solveTab(string& text1, string& text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) 
                    ans = 1+dp[i+1][j+1];
                else 
                    ans = max(dp[i][j+1], dp[i+1][j]);
                
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    //Time Complexity => O(n*m)
    //Space Complexity => O(m)
    int solveSO(string& text1, string& text2) {
        int n = text1.length();
        int m = text2.length();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) 
                    ans = 1+next[j+1];
                else 
                    ans = max(curr[j+1], next[j]);
                
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        // //Recursion
        // return solveRec(text1, text2, 0, 0);


        // //Recursion + Memoization
        // int n = text1.length();
        // int m = text2.length();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // return solveMem(text1, text2, 0, 0, dp);


        // //Tabulation
        // return solveTab(text1, text2);


        //Space-Optimization
        return solveSO(text1, text2);

    }
};
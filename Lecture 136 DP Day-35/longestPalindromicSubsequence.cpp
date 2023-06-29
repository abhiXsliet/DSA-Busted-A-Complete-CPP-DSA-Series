// https://leetcode.com/problems/longest-palindromic-subsequence/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(2^n) -> since n==m 
    //Space Complexity => O(2n) => O(n) -> recursive call stack space
    int solveRec(string& s, string& rStr, int i, int j) {
        int n = s.length();
        int m = rStr.length();

        //base case
        if(i == n || j == m)
            return 0;
        int ans = 0;
        if(s[i] == rStr[j]) 
            ans = 1 + solveRec(s, rStr, i+1, j+1);
        else 
            ans = max(solveRec(s, rStr, i, j+1), solveRec(s, rStr, i+1, j));
        
        return ans;
    }

    //Time Complexity => O(n*m) => O(n^2) since n == m
    //Space Complexity => O(n*m) => O(n) 
    int solveMem(string& s, string& rStr, int i, int j, vector<vector<int>>& dp) {
        int n = s.length();
        int m = rStr.length();

        //base case
        if(i == n || j == m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(s[i] == rStr[j]) 
            ans = 1 + solveMem(s, rStr, i+1, j+1, dp);
        else 
            ans = max(solveMem(s, rStr, i, j+1, dp), solveMem(s, rStr, i+1, j, dp));
        
        return dp[i][j] = ans;
    }


    //Time Complexity => O(n*m) => O(n^2) since n == m
    //Space Complexity => O(n*m) => O(n) 
    int solveTab(string& s, string& rStr) {
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int ans = 0;
                if(s[i] == rStr[j]) 
                    ans = 1 + dp[i+1][j+1];
                else 
                    ans = max(dp[i][j+1], dp[i+1][j]);
                
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }


    //Time Complexity => O(n*m) => O(n^2) since n == m
    //Space Complexity => O(n) 
    int solveSO(string& s, string& rStr) {
        int n = s.length();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int ans = 0;
                if(s[i] == rStr[j]) 
                    ans = 1 + next[j+1];
                else 
                    ans = max(curr[j+1], next[j]);
                
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }


public:
    int longestPalindromeSubseq(string s) {
        string rStr = s;
        reverse(rStr.begin(), rStr.end());

        // // Recursive solution -> TLE
        // return solveRec(s, rStr, 0, 0);


        // //Recursion + Memoization
        // int n = s.length();
        // int m = rStr.length();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // return solveMem(s, rStr, 0, 0, dp);


        // //Tabulation
        // return solveTab(s, rStr);


        //Space-Optimization
        return solveSO(s, rStr);

    }
};
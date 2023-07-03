// https://leetcode.com/problems/wildcard-matching/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Time Complexity => O(2^(n+m))
    // Space Complexity => O(n+m) -> recursive call stack
    bool solveRec(string& s, string& p, int i, int j) {
        //base case
        if(i<0 && j<0)
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0) {
            for(int i=0; i<=j; i++){
                if(p[i] != '*')
                    return false;
            }
            return true;
        }
        
        //match
        if(s[i] == p[j] || p[j] == '?')
            return solveRec(s, p, i-1, j-1);

        else if(p[j] == '*') 
            return ( solveRec(s, p, i, j-1) || solveRec(s, p, i-1, j) );
        else 
            return false;
    }

    // Time Complexity => O(n*m)
    // Space Complexity => O(n*m)
    bool solveMem(string& str, string& pattern, int i, int j, vector<vector<int>>& dp) {
        
        //base case
        // if(i<0 && j<0) //0-based indexing
        if(i==0 && j==0) //1-based indexing
            return true;

        // if(i>=0 && j<0) //0-based indexing
        if(i>0 && j==0) //1-based indexing
            return false;

        // if(i<0 && j>=0) { //0-based indexing
        if(i==0 && j>0) { //1-based indexing

            // for(int i=0; i<=j; i++) { //0-based indexing
            for (int k = 1; k <= j; k++) {
                if (pattern[k - 1] != '*') // 1-based indexing
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        //match
        // if(str[i] == pattern[j] || pattern[j] == '?') //0-based indexing
        if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') //1-based indexing
            return dp[i][j] = solveMem(str, pattern, i-1, j-1, dp);

        // else if(pattern[j] == '*') //0-based indexing
        else if(pattern[j-1] == '*') //1-based indexing
        return dp[i][j] = ( solveMem(str, pattern, i-1, j, dp) || solveMem(str, pattern, i, j-1, dp) );
        else 
            return false;
    }

    // Time Complexity => O(n*m)
    // Space Complexity => O(n*m)
    bool solveTab(string& str, string& pattern) {
        int n = str.length();
        int m = pattern.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        //After analyzing base case
        dp[0][0] = true;

        for(int j=1; j<=m; j++) {
            bool flag = true;
            for(int k=1; k<=j; k++) {
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                //match
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(pattern[j-1] == '*')
                    dp[i][j] = ( dp[i-1][j] || dp[i][j-1] );
                else 
                    dp[i][j] = false;
            }
        }
        return dp[n][m];

    }

    // Time Complexity => O(n*m)
    // Space Complexity => O(m)
    bool solveSO(string& str, string& pattern) {
        int n = str.length();
        int m = pattern.length();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        //After analyzing base case
        prev[0] = true;

        for(int j=1; j<=m; j++) {
            bool flag = true;
            for(int k=1; k<=j; k++) {
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                //match
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    curr[j] = prev[j-1];
                else if(pattern[j-1] == '*')
                    curr[j] = ( prev[j] || curr[j-1] );
                else 
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];

    }

public:
    bool isMatch(string s, string p) {

        // //Recursive Solution
        // int n = s.length()-1;
        // int m = p.length()-1;
        // return solveRec(s, p, n, m);


        //Memoization + Recursion
        // int n = s.length();
        // int m = p.length();
        //         //0-based indexing
        // // vector<vector<int>> dp(n, vector<int>(m, -1));
        // // return solveMem(s, p, n-1, m-1, dp);

        //         //1-based indexing
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solveMem(s, p, n, m, dp);


        // //Tabulation
        // return solveTab(s, p);


        //Space-Optimization
        return solveSO(s, p);

    }
};
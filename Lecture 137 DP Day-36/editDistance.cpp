// https://leetcode.com/problems/edit-distance/



#include<bits/stdc++.h>
using namespace std;

class Solution {

    //Time Complexity => O(3^(n+m))
    //Space Complexity => O(n+m) -> (i.e., the maximum length of the call stack)
    int solveRec(string& word1, string& word2, int i, int j) {
        int n = word1.length();
        int m = word2.length();
        //base case
        if(i == n)
            return (m-j);

        if(j == m)
            return (n-i);

        int ans = 0;
        if(word1[i] == word2[j]) {
            ans = solveRec(word1, word2, i+1, j+1);
        } else {
            int insertAns = 1 + solveRec(word1, word2, i, j+1);
            int deleteAns = 1 + solveRec(word1, word2, i+1, j);
            int replaceAns = 1+ solveRec(word1, word2, i+1, j+1);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }

    //Time Complexity => O(n*m)
    //Space Complexity => O(n*m)
    int solveMem(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        int n = word1.length();
        int m = word2.length();
        //base case
        if(i == n)
            return (m-j);

        if(j == m)
            return (n-i);

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(word1[i] == word2[j]) {
            ans = solveMem(word1, word2, i+1, j+1, dp);
        } else {
            int insertAns = 1 + solveMem(word1, word2, i, j+1, dp);
            int deleteAns = 1 + solveMem(word1, word2, i+1, j, dp);
            int replaceAns = 1+ solveMem(word1, word2, i+1, j+1, dp);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }

    //Time Complexity => O(n*m)
    //Space Complexity => O(n*m)
    int solveTab(string& word1, string& word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        //after analyzing base case
        for(int j=0; j<=m; j++) 
            dp[n][j] = m-j;

        for(int i=0; i<=n; i++)
            dp[i][m] = n-i;

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(word1[i] == word2[j]) {
                    ans = dp[i+1][j+1];
                } else {
                    int insertAns = 1 + dp[i][j+1];
                    int deleteAns = 1 + dp[i+1][j];
                    int replaceAns = 1+ dp[i+1][j+1];
                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    //Time Complexity => O(n*m)
    //Space Complexity => O(m)
    int solveSO(string& word1, string& word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        //after analyzing base case
        for(int j=0; j<=m; j++) 
            next[j] = m-j;

        for(int i=n-1; i>=0; i--) {   
            //catch -> after analyzing base case
            curr[m] = n-i;

            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(word1[i] == word2[j]) {
                    ans = next[j+1];
                } else {
                    int insertAns = 1 + curr[j+1];
                    int deleteAns = 1 + next[j];
                    int replaceAns = 1+ next[j+1];
                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int minDistance(string word1, string word2) {
        // //Recursive solution
        // return solveRec(word1, word2, 0, 0);


        // //Recursion + Memoization
        // vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        // return solveMem(word1, word2, 0, 0, dp);


        // //Tabulation
        // return solveTab(word1, word2);


        //Space Optimization
        return solveSO(word1, word2);

    }
};
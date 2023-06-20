//https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solveRec(vector<int>& v, int i, int j) {
        //base case 
        if(i+1 == j) {
            return 0;
        }

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++) {
            ans = min(ans, v[i]*v[j]*v[k] + solveRec(v, i, k) + solveRec(v, k, j));
        }
        return ans;
    }

    int solveMem(int i, int j, vector<int>& v, vector<vector<int>> &dp ){
        //base case
        if(i+1 == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++) {
            ans = min(ans, v[i]*v[j]*v[k] 
                            + solveMem(i, k, v, dp) + solveMem(k, j, v, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(vector<int>& v) {

        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+2; j<n; j++) {

                int ans = INT_MAX;
                for(int k=i+1; k<j; k++){
                    ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
public:
    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();
        // return solveRec(values, 0, n-1);

        // //Recursion+Memozation
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMem(0, n-1, values, dp);

        //Tabulation
        return solveTab(values);

    }
};
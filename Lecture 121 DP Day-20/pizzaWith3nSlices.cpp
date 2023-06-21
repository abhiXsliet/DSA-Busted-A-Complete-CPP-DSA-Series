//https://leetcode.com/problems/pizza-with-3n-slices/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(2^n)
    //Space Complexity => O(n) -> Recursive call stack
    int solveRec(vector<int>& slices, int startIdx, int endIdx, int n) {
        //base case
        if(n == 0 || startIdx > endIdx)
            return 0;
        
        int include = slices[startIdx] + solveRec(slices, startIdx+2, endIdx, n-1);
        int exclude = 0 + solveRec(slices, startIdx+1, endIdx, n);

        return max(include, exclude);
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveMem(vector<int>& slices, int startIdx, int endIdx, int n, vector<vector<int>>& dp) {
        //base case
        if(n == 0 || startIdx > endIdx)
            return 0;
        
        if(dp[startIdx][n] != -1) 
            return dp[startIdx][n];
        
        int include = slices[startIdx] + solveMem(slices, startIdx+2, endIdx, n-1, dp);
        int exclude = 0 + solveMem(slices, startIdx+1, endIdx, n, dp);

        return dp[startIdx][n] = max(include, exclude);
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveTab(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k+2, vector<int>(k+2, 0));
        vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));

        for(int i=k-2; i>=0; i--) {
            for(int n=1; n<=k/3; n++) {
                int include = slices[i] + dp1[i+2][n-1];
                int exclude = 0 + dp1[i+1][n];

                dp1[i][n] = max(include, exclude);
            }
        }
        int case1 = dp1[0][k/3];

        for(int i=k-1; i>=0; i--) {
            for(int n=1; n<=k/3; n++) {
                int include = slices[i] + dp2[i+2][n-1];
                int exclude = 0 + dp2[i+1][n];

                dp2[i][n] = max(include, exclude);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1, case2);
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n)
    int solveSO(vector<int>& slices) {
        int k = slices.size();
        vector<int> prev1(k+2, 0);
        vector<int> curr1(k+2, 0);
        vector<int> next1(k+2, 0);

        vector<int> prev2(k+2, 0);
        vector<int> curr2(k+2, 0);
        vector<int> next2(k+2, 0);

        for(int i=k-2; i>=0; i--) {
            for(int n=1; n<=k/3; n++) {
                int include = slices[i] + next1[n-1];
                int exclude = 0 + curr1[n];

                prev1[n] = max(include, exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k/3];

        for(int i=k-1; i>=1; i--) {
            for(int n=1; n<=k/3; n++) {
                int include = slices[i] + next2[n-1];
                int exclude = 0 + curr2[n];

                prev2[n] = max(include, exclude);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k/3];

        return max(case1, case2);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();

        // //Recursion
        // int case1 = solveRec(slices, 0, k-2, k/3);
        // int case2 = solveRec(slices, 1, k-1, k/3);
        // return max(case1, case2);
        
        // //Memoization -> Top-Down Approach
        // vector<vector<int>>dp1(k, vector<int>(k, -1));
        // vector<vector<int>>dp2(k, vector<int>(k, -1));
        // int case1 = solveMem(slices, 0, k-2, k/3, dp1);
        // int case2 = solveMem(slices, 1, k-1, k/3, dp2);
        // return max(case1, case2);

        // //Tabulation
        // return solveTab(slices);

        //Space Optimized
        return solveSO(slices);
    }
};
//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int> base, vector<int> newBox) {
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
            return true;
        else 
            return false;
    }

    //Time Complexity => O(2^n)
    //Space Complexity => O(n) -> Recursion Stack Space
    int solveRec(vector<vector<int>>& cub, int curr, int prev, int n) {
        //base case
        if(curr == n)
            return 0;

        int include = INT_MIN;
        if(prev == -1 || (cub[curr][1] >= cub[prev][1] && cub[curr][2] >= cub[prev][2])) {
            include = cub[curr][2] + solveRec(cub, curr+1, curr, n);
        }
        int exclude = solveRec(cub, curr+1, prev, n);

        return max(include, exclude);
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveMem(vector<vector<int>>& cub, vector<vector<int>>&dp, int curr, int prev, int n) {
        //base case
        if(curr == n)
            return 0;

        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];

        int include = INT_MIN;
        if(prev == -1 || (cub[curr][1] >= cub[prev][1] 
                            && cub[curr][2] >= cub[prev][2])) {

            include = cub[curr][2] + solveMem(cub, dp, curr+1, curr, n);
        }
        int exclude = solveMem(cub, dp, curr+1, prev, n);

        return dp[curr][prev+1] = max(include, exclude);
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveTab(vector<vector<int>>& cub, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr; prev>=-1; prev--) {
                int include = INT_MIN;
                if(prev == -1 || (cub[curr][1] >= cub[prev][1] 
                    && cub[curr][2] >= cub[prev][2])) {

                    include = cub[curr][2] + dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n)
    int solveSO(int n, vector<vector<int>>& cuboids) {

        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                
                int include = 0, exclude = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev])) 
                    include = cuboids[curr][2] + nextRow[curr+1];
                
                exclude = nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n)
    int solveAnotherWay(int n, vector<vector<int>>& cuboids) {

        vector<int> dp(n, 0);
        int maxHeight = 0;

        for(int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
            for(int j = 0; j < i; j++) {
                if(cuboids[j][0] <= cuboids[i][0] 
                    && cuboids[j][1] <= cuboids[i][1] 
                    && cuboids[j][2] <= cuboids[i][2]) {

                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }
        return maxHeight;
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        //step-1: sort all dimensions of every cuboids
        for(auto &a: cuboids) {
            sort(a.begin(), a.end());
        }

        //step-2: sort all cuboids basis on w or l
        sort(cuboids.begin(), cuboids.end());

        // //Recursion -> TLE
        int n = cuboids.size();
        // return solveRec(cuboids, 0, -1, n);

        // //Recursion + Memoization
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveMem(cuboids, dp, 0, -1, n);

        // //Tabulation
        // return solveTab(cuboids, n);

        //step-3: use the logic of LIS problem
        return solveSO(cuboids.size(), cuboids);
        
        // return solveAnotherWay(cuboids.size(), cuboids);

    }
};
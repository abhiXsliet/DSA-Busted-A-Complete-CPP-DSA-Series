//https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(2^n)
    //Space Complexity => O(n)
    int solveRec(vector<int>& arr, map<pair<int, int>, int>& maxi , int left, int right) {
        //base case
        if(left == right)   
            return 0;

        int mini = INT_MAX;
        //partitioned at k
        for(int k=left; k<right; k++) {
            mini = min( mini, maxi[{left, k}]*maxi[{k+1, right}] + 
                    solveRec(arr, maxi, left, k) + solveRec(arr, maxi, k+1, right) );
        }
        return mini;
    }

    //Time Complexity => O(n^3)
    //Space Complexity => O(n^2)
    int solveMem(vector<int>& arr, map<pair<int, int>, int>& maxi , int left, int right, vector<vector<int>>& dp) {
        //base case
        if(left == right)   
            return 0;
        
        if(dp[left][right] != -1)
            return dp[left][right];

        int mini = INT_MAX;
        //partitioned at k
        for(int k=left; k<right; k++) {
            mini = min( mini, maxi[{left, k}]*maxi[{k+1, right}] + 
                    solveMem(arr, maxi, left, k, dp) + solveMem(arr, maxi, k+1, right, dp) );
        }
        return dp[left][right] = mini;
    }


public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        
        map<pair<int, int>, int> maxi;
        for(int i=0; i<n; i++) {
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        // //Recursive -> TLE
        // return solveRec(arr, maxi, 0, n-1);


        //Memoization
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solveMem(arr, maxi, 0, n-1, dp);
        

    }
};
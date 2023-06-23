//https://leetcode.com/problems/longest-arithmetic-subsequence/


#include<bits/stdc++.h>
using namespace std;

class Solution {

    //Time Complexity => O(n^2)
    //Space Complexity => O(n) -> Recursive call stack
    int solveRec(vector<int>& nums, int index, int diff) {
        //base case
        if(index < 0)
            return 0;
        
        int ans = 0;
        //Backward logic
        for(int j=index-1; j>=0; j--) {
            if(nums[index]-nums[j] == diff)
                ans = max(ans, (1 + solveRec(nums, j, diff)) );
        }
        return ans;
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveMem(vector<int>& nums, int index, int diff, unordered_map<int, int> dp[]) {
        //base case
        if(index < 0)
            return 0;
        
        if(dp[index].count(diff))
            return dp[index][diff];

        int ans = 0;
        //Backward logic
        for(int j=index-1; j>=0; j--) {
            if(nums[index]-nums[j] == diff)
                ans = max(ans, (1 + solveMem(nums, j, diff, dp)) );
        }
        return dp[index][diff] = ans;
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveTab(vector<int>& nums, int n, int ans) {
    
        unordered_map<int, int> dp[n+1];

        for(int index=1; index<n; index++) {
            for(int j=0; j<index; j++) {
                int diff = nums[index] - nums[j];
                int cnt = 1;

                //check if ans is already present
                if(dp[j].count(diff))
                    cnt = dp[j][diff];

                dp[index][diff] = 1+cnt;
                ans = max(ans, dp[index][diff]);
            }
        }
        return ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;
        int ans = 0;
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         int diff = nums[j] - nums[i];
        //         ans = max( ans, (2 + solveRec(nums, i, diff)) );
        //     }
        // }
        // return ans;
        

        // //Memoization -> Top-Down
        // unordered_map<int, int>dp[n+1];
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         int diff = nums[j] - nums[i];
        //         ans = max( ans, (2 + solveMem(nums, i, diff, dp)) );
        //     }
        // }
        // return ans;

        
        //Tabulation -> Bottom-Up
        return solveTab(nums, n, ans);
        
    }
};
//https://leetcode.com/problems/partition-equal-subset-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(2^n)
    //Space Complexity => O(n) -> Recursive Call Stack
    bool solveRec(vector<int>& nums, int target, int index) {
        int n = nums.size();
        //base case 
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(index >= n)
            return 0;

        bool incl = solveRec(nums, target-nums[index], index+1);
        bool excl = solveRec(nums, target, index+1);

        return (incl || excl);
    }

    //Time Complexity => O(n^2)  -> O(index*target)
    //Space Complexity => O(n^2) -> O(index*target)
    bool solveMem(vector<int>& nums, int target, int index, vector<vector<int>>& dp) {
        int n = nums.size();
        //base case 
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(index >= n)
            return 0;

        if(dp[index][target] != -1)
            return dp[index][target];

        bool incl = solveMem(nums, target-nums[index], index+1, dp);
        bool excl = solveMem(nums, target, index+1, dp);

        return dp[index][target] = (incl || excl);
    }

    //Time Complexity => O(n^2)  -> O(index*target)
    //Space Complexity => O(n^2) -> O(index*target)
    bool solveTab(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        //after analyzing base case
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;

        for(int index=n-1; index>=0; index--) {
            for(int tar=0; tar<=target; tar++) {
                bool incl = 0;
                if(tar-nums[index] >= 0)
                    incl = dp[index+1][tar-nums[index]];
                bool excl = dp[index+1][tar];
                dp[index][tar] = (incl || excl);
            }
        }
        return dp[0][target];
    }

    //Time Complexity => O(n^2) -> O(index*target)
    //Space Complexity => O(n)  -> O(target)
    bool solveSO(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);

        //after analyzing base case
        curr[0] = 1;
        next[0] = 1;

        for(int index=n-1; index>=0; index--) {
            for(int tar=0; tar<=target; tar++) {
                bool incl = 0;
                if(tar-nums[index] >= 0)
                    incl = next[tar-nums[index]];
                bool excl = next[tar];
                curr[tar] = (incl || excl);
            }
            next = curr;
        }
        return next[target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        int index = 0;
        for(int i=0; i<nums.size(); i++) {
            target += nums[i];
        }
        // // if(target%2 == 0) {
        // //     target-= target/2;
        // // } else {
        // //     return 0;
        // // }

        if(target & 1)
            return 0;
        target = target /2;

        // //Recursive
        // return solveRec(nums, target, index);

        // //Memoization
        // vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));
        // return solveMem(nums, target, index, dp);

        // //Tabulation
        // return solveTab(nums, target);

        //Space Optimization
        return solveSO(nums, target);

    }
};
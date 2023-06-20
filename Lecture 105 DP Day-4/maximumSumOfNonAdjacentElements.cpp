//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h> 
using namespace std;

int solveRec(vector<int> &nums, int n) {

    //base case
    if(n == 0)
        return nums[0];
    if(n < 0) 
        return 0;

    //recursive calls
    int incl = solveRec(nums, n-2) + nums[n];
    int excl = solveRec(nums, n-1) + 0;

    return max(incl, excl);
}

//solution using Recursion + Memoization -> Top-Down Approach 
//Time Complexity =>  O(N)
//Space Complexity => O(N) + O(N) -> dp(n) + recursion depth
int solveMem(vector<int> &nums, int n, vector<int>& dp) {
    //base case
    if(n < 0) 
        return 0;
    if(n == 0)
        return nums[0];

    //step-2 : return after base cases
    if(dp[n] != -1)
        return dp[n];

    int incl = solveMem(nums, n-2, dp) + nums[n];
    int excl = solveMem(nums, n-1, dp) + 0;

    //step-3 : store ans in dp-array
    dp[n] = max(incl, excl);
    return dp[n];
}

//solution using Tabulation -> Bottom-Up Approach
//Time and Space Complexity => O(N)
int solveTab(vector<int>& nums) {
    //step-1: creation of dp-array
    int n = nums.size();
    vector<int> dp(n, 0);

    //step-2: store values in dp
    dp[0] = nums[0];

    //step-3: looping for the remaining cases
    for(int i=1; i<n; i++) {
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }
    return dp[n-1];
}

//solution using space optimization 
//Time Complexity => O(N)
//Space Complexity => O(1)
int solveSpaceOpt(vector<int>& nums) {
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;

    for(int i=1; i<n; i++) {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){

    // int n = nums.size();
    // solveRec(nums, n-1);

    // //Recursion+Memoization -> Top-Bottom Approach
    // //step-1 : creation of 1-D Array
    // int n = nums.size();
    // vector<int> dp(n, -1);
    // int ans = solveMem(nums, n-1, dp);
    // return ans;

    // //Tabulation -> Bottom-Up Approach
    // int ans = solveTab(nums);
    // return ans;

    //Space Optimisation
    return solveSpaceOpt(nums);
}
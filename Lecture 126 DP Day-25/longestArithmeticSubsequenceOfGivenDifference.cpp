//https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int>dp;
        int ans = 0;

        for(int i=0; i<n; i++) {
            int temp = arr[i]-difference;
            int tempAns = 0;
            //check if the answer is already exists for the temp
            if(dp.count(temp))
                tempAns = dp[temp];

            //update the current answer
            dp[arr[i]] = 1+tempAns;

            //update the ans
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};
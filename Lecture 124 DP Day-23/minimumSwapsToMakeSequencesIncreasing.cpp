//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/


#include<bits/stdc++.h>
using namespace std;

class Solution {

    //Time Complexity => O(2^n)
    //Space Complexity => O(n) -> Recursive Call Stack
    int solveRec(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
        //base case
        if(index >= nums1.size()) 
            return 0;

        //find prev1 and prev2
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //catch -> if swapped is true
        if(swapped)
            swap(prev1, prev2);
        
        //no-swap
        int ans = INT_MAX;
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = 0 + solveRec(nums1, nums2, index+1, 0);

        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min( ans, ( 1 + solveRec(nums1, nums2, index+1, 1)) );

        return ans;
    }

    //Time Complexity => O(n)
    //Space Complexity => O(n) -> since there is only 2-columns
    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, 
                bool swapped, vector<vector<int>>& dp) {

        //base case
        if(index >= nums1.size()) 
            return 0;

        if(dp[index][swapped] != -1)
            return dp[index][swapped];

        //find prev1 and prev2
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //catch -> if swapped is true
        if(swapped)
            swap(prev1, prev2);
        
        //no-swap
        int ans = INT_MAX;
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = 0 + solveMem(nums1, nums2, index+1, 0, dp);

        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min( ans, ( 1 + solveMem(nums1, nums2, index+1, 1, dp)) );

        return dp[index][swapped] = ans;
    }

    //Time Complexity => O(n) -> Inner loop running only 2-times
    //Space Complexity => O(n) -> since 2-D vector has only columns
    int solveTab(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>>dp(nums1.size()+1, vector<int>(2, 0));

        for(int index=nums1.size()-1; index>=1; index--) {
            for(int swapped=1; swapped>=0; swapped--) {
                        
                //find prev1 and prev2
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                //catch -> if swapped is true
                if(swapped)
                    swap(prev1, prev2);
                
                //no-swap
                int ans = INT_MAX;
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = 0 + dp[index+1][0];

                //swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min( ans, ( 1 + dp[index+1][1]) );

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    //Time Complexity => O(n)
    //Space Complexity => O(1)  
    int solveSO(vector<int>& nums1, vector<int>& nums2) {

        int swap = 0;
        int noSwap = 0;
        int currSwap = 0;
        int currNoSwap = 0;

        for(int index=nums1.size()-1; index>=1; index--) {
            for(int swapped=1; swapped>=0; swapped--) {
                        
                //find prev1 and prev2
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                //catch -> if swapped is true
                if(swapped){
                    int temp = prev1;
                    prev1 = prev2;
                    prev2 = temp;
                }
                
                //no-swap
                int ans = INT_MAX;
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = 0 + noSwap;

                //swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min( ans, ( 1 + swap) );

                if(swapped)
                    currSwap = ans;
                else 
                   currNoSwap = ans;
            }
            swap = currSwap;
            noSwap = currNoSwap;
        }
        return min(swap, noSwap);
    }


public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //insert -1 in the beginning of nums1 and nums2
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        bool swapped = 0;
        int index = 1;
        // return solveRec(nums1, nums2, index, swapped);

        // //Memoization+Recursion
        // vector<vector<int>>dp(nums1.size(), vector<int>(2, -1));
        // return solveMem(nums1, nums2, index, swapped, dp);

        // //Tabulation
        // return solveTab(nums1, nums2);

        //Space Optimization
        return solveSO(nums1, nums2);
    }
};
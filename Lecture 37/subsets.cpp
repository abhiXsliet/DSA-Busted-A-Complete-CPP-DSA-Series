// https://leetcode.com/problems/subsets/


// Set of all subsets is called POWER SET.
// POWER SET = 2^n where n = no. of elements in a set

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans){

        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        solve(nums, output, index+1, ans);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;

    }
};


//Do these problems with the help of bits manipulation

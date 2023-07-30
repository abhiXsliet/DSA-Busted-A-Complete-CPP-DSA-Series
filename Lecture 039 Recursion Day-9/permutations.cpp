// https://leetcode.com/problems/permutations/



#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void permutation(vector<int>nums, int index, vector<vector<int> >& ans){

        //base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);

            //recursive call
            permutation(nums, index+1, ans);

            //backtrack
            swap(nums[i], nums[index]);

        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        int index = 0;

        permutation(nums, index, ans);

        return ans;
    }
};
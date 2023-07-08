//https://leetcode.com/problems/find-all-duplicates-in-an-array/description/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
/* 
        // Time Complexity => O(N)
        // Space Complexity => O(N)
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        for(auto& i: map) {
            if(i.second > 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
     */

        // Time Complexity => O(N)
        // Space Complexity => O(1)
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int index = abs(nums[i])-1;
            int element = nums[index];
            if(element < 0)
                ans.push_back(abs(nums[i]));

            nums[index] = nums[index] * (-1);
        }
        return ans;
    }
};
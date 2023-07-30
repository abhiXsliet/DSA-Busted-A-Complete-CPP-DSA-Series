// https://leetcode.com/problems/rotate-array/


//////////////////////////////////////////////////
// shift i-th term to k-position in cyclic way ///
// arr[(i + k)%n] = arr[i]                       ///
//////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>temp(n);
        for(int i=0; i<n; i++) {
            temp[(i+k)%n] = nums[i];
        }
        nums = temp;
    }
};
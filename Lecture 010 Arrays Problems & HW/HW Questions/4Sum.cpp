// https://leetcode.com/problems/4sum/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

/* 
    // Time Complexity => O(N^3 * log(N)) // operations like find() and insert() takes O(log n) time on average for a set.
    // Space Complexity => 2*O(No. of quadruplets) = 2*O(N4) -> one for set and other for returning the answer
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> store;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                set<long long>st;
                for(int k=j+1; k<n; k++) {

                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long ele = target - (sum);

                    if(st.find(ele) != st.end()) {
                        vector<int>temp = {nums[i], nums[j], nums[k], static_cast<int>(ele)};
                        sort(temp.begin(), temp.end());
                        store.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(store.begin(), store.end());
        return ans;
    }

 */



    // Time Complexity => O(N^3)
    // Space Complexity => O(1) for the algo.
    // O(no. of quadruplets) space for returning the ans
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int l = n - 1;
                while( k < l ) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target) {
                        vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;

                    } else if( sum < target ) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/russian-doll-envelopes/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        //if widths are same  
        if(a[0] == b[0])
            //return the height in increasing order
            return a[1] > b[1];
        
        // return width in increasing order
        return a[0] < b[0];
    }

    // Time Complexity => Nlog(N)
    // Space Complexity => O(N)
    int solveOptimal(vector<vector<int>>& envelopes, int n) {
        //base case
        if(n == 0) return 0;

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(ans.empty() || envelopes[i][1] > ans.back()) 
                ans.push_back(envelopes[i][1]);
            else {
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        int n = envelopes.size();
        return solveOptimal(envelopes, n);
    }
};
//https://leetcode.com/problems/min-cost-climbing-stairs/
//Time Complexity will be O(N)
//Space Complexity will be O(N)


#include<bits/stdc++.h>
using namespace std;

class Solution {

    int solveDP2(vector<int>& cost, int n) {
        //step-1: creation of dp array
        vector<int> dp(n+1);
        //step-2: analyse the base case
        dp[0] = cost[0];
        dp[1] = cost[1];

        //step-3: handle remaining cases using loop
        for(int i=2; i<n; i++) {
            dp[i] = cost[i] + min( dp[i-1] , dp[i-2] );
        }
        return min(dp[n-1], dp[n-2]);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {

        //By using Bottom - Up Approach
        int n = cost.size();
        return solveDP2(cost, n);


        return 0;
    }
};
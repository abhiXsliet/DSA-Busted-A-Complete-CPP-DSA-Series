//https://leetcode.com/problems/min-cost-climbing-stairs/
//Time Complexity will be O(N)
//Space Complexity will be O(N) + O(N) = O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRec(vector<int>& cost, int n) {
        //base case
        if(n==0)
            return cost[0];

        if(n==1)
            return cost[1];

        return cost[n] + min(solveRec(cost, n-1) , solveRec(cost, n-2));
    }

    int solveDP1(vector<int>& cost, int n, vector<int>& dp) {

        //base case
        if(n == 0) 
            return cost[0];

        if(n == 1) 
            return cost[1];

        //step-3
        if(dp[n] != -1) 
            return dp[n];

        //step-2
        return dp[n] = cost[n] + min( solveDP1(cost,n-1, dp), solveDP1(cost, n-2, dp) );

    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        // //By using Recursion
        // int n = cost.size();
        // return min( solveRec(cost, n-1) , solveRec(cost, n-2) );

        //By using Top - Down Approach
        int n = cost.size();
        //step-1
        vector<int> dp(n+1, -1);
        return min( solveDP1(cost, n-1, dp), solveDP1(cost, n-2, dp));


        return 0;
    }
};
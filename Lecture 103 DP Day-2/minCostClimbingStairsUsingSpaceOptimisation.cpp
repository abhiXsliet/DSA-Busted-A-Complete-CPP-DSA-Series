//https://leetcode.com/problems/min-cost-climbing-stairs/
//Time Complexity will be O(N)
//Space Complexity will be O(1)


#include<bits/stdc++.h>
using namespace std;

class Solution {

    int solveDP3(vector<int>& cost, int n) {

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2; i<n; i++) {
            int curr = cost[i] + min( prev1, prev2 );
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        //By using space optimization
        int n = cost.size();
        return solveDP3(cost, n);


        return 0;
    }
};
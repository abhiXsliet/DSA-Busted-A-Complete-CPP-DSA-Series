//https://leetcode.com/problems/minimum-sideway-jumps/

#include<bits/stdc++.h>
using namespace std;

class Solution {

    //Time Complexity => (2^n) 
    //Space Complexity => O(4*n)
    int solveRec(vector<int>& obs, int currLane, int currPos) {

        int n = obs.size() - 1;
        //base case
        if(currPos == n)
            return 0;
        
        if(obs[currPos+1] != currLane) {
            return solveRec(obs, currLane, currPos+1);
        }
        else {
            //sideways jump
            int ans = INT_MAX;
            for(int i=1; i<=3; i++) {

                if(currLane != i && obs[currPos] != i)
                    ans = min(ans, 1+ solveRec(obs, i, currPos));
            }
            return ans;
        }
    }

    //Time Complexity => O(n)
    //Space Complexity => O(4*n)
    int solveMem(vector<int>& obs, int currLane, int currPos, vector<vector<int>>& dp){
        int n = obs.size()-1;

        //base case
        if(currPos == n)
            return 0;

        if(dp[currLane][currPos] != -1)
            return dp[currLane][currPos];

        if(obs[currPos+1] != currLane)
            return solveMem(obs, currLane, currPos+1, dp);
        else {
            //sideways jump
            int ans = INT_MAX;
            for(int i=1; i<=3; i++) {
                if(currLane != i && obs[currPos] != i) 
                    ans = min(ans, 1+solveMem(obs, i, currPos, dp));
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }

    //Time Complexity => O(n) 
    //Space Complexity => O(4*n)
    int solveTab(vector<int>& obs) {

        int n = obs.size()-1;
        vector<vector<int> > dp(4, vector<int>(obs.size(), 1e9));
        
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int currPos=n-1; currPos>=0; currPos--) {
            for(int currLane = 1; currLane <= 3; currLane++) {
                if(obs[currPos+1] != currLane) 
                    dp[currLane][currPos] = dp[currLane][currPos+1];
                else {
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(currLane != i && obs[currPos] != i)
                            ans = min(ans, 1+dp[i][currPos+1]);
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }

    //Time Complexity => O(n) 
    //Space Complexity => O(1)
    int solveSO(vector<int>& obs) {

        int n = obs.size()-1;
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int currPos=n-1; currPos>=0; currPos--) {
            for(int currLane=1; currLane<=3; currLane++) {
                if(obs[currPos+1] != currLane) 
                    curr[currLane] = next[currLane];
                else {
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(currLane != i && obs[currPos] != i)
                            ans = min(ans, 1+next[i]);
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1+next[1], 1+next[3]));
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        //Recursive solution
        // return solveRec(obstacles, 2, 0);

        // //Top-Down Approach (Memoization)
        // vector<vector<int> > dp(4, vector<int>(obstacles.size(), -1));
        // return solveMem(obstacles, 2, 0, dp);

        // ///Bottom-Up Approach (Tabulation)
        // return solveTab(obstacles);

        //Space-Optimized
        return solveSO(obstacles);

    }
};
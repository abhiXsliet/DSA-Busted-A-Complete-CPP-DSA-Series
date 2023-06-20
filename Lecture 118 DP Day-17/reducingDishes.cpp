// https://leetcode.com/problems/reducing-dishes/

#include<bits/stdc++.h>
using namespace std;

class Solution {

    //Time Complexity => exponential O(2^n)
    //Space Complexity => O(n)-> size of satisfaction vector
    int solveRec(vector<int>& satisfaction, int index, int time) {
        //base case
        if(index == satisfaction.size())    
            return 0;

        int include = time*satisfaction[index] 
                        + solveRec(satisfaction, index+1, time+1);

        int exclude = solveRec(satisfaction, index+1, time);

        return max(include, exclude);
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveMem(vector<int>& satisfaction, int idx, int time, vector<vector<int>>&dp) {
        //base case
        if(idx == satisfaction.size())
            return 0;

        if(dp[idx][time] != -1)
            return dp[idx][time];

        int incl = satisfaction[idx]*(time+1) 
                        + solveMem(satisfaction, idx+1, time+1, dp);

        int excl = solveMem(satisfaction, idx+1, time, dp);

        return dp[idx][time] = max(incl, excl);
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n^2)
    int solveTab(vector<int>& satisfaction) {
        int n= satisfaction.size();
        //step-1
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        //handle the remaining n-1 cases
        for(int index = n-1; index>=0; index--) {
            for(int time=index; time>=0; time--) {
                int incl = satisfaction[index]*(time+1) + dp[index+1][time+1];
                int excl = dp[index+1][time];

                dp[index][time] = max(incl, excl);
            }
        }
        return dp[0][0];
    }

    //Time Complexity => O(n^2)
    //Space Complexity => O(n)
    int solveSO(vector<int>& satisfaction) {
        int n = satisfaction.size();

        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);

        for(int index=n-1; index>=0; index--) {
            for(int time=index; time>=0; time--) {
                
                int incl = satisfaction[index]*(time+1) + next[time+1];
                int excl = next[time];
                
                curr[time] = max(incl, excl);
            } next = curr;
        }
       return next[0];
    }

    

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        //step-1: sort
        sort(satisfaction.begin(), satisfaction.end());
        // return solveRec(satisfaction, 0, 1);

        int n = satisfaction.size();
        // // Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(satisfaction, 0, 0, dp);


        // //Tabulation
        // return solveTab(satisfaction);


        //Space Optimization
        return solveSO(satisfaction);

    }
};


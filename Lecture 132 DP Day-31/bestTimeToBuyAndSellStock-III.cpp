//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(2^n)
    //Space Complexity => O(n)
    int solveRec(vector<int>& prices, int index, int buy, int limit) {
        int n = prices.size();
        //base case 
        if(index == n)
            return 0;

        if(limit == 0)
            return 0;
        
        int profit = INT_MIN;
        if(buy) {
            int canBuy = -prices[index] + solveRec(prices, index+1, 0, limit);
            int skipBuy = 0 + solveRec(prices, index+1, 1, limit);
            profit = max(canBuy, skipBuy);
        } else {
            int sell = +prices[index] + solveRec(prices, index+1, 1, limit-1);
            int skipSell = 0 + solveRec(prices, index+1, 0, limit);
            profit = max(sell, skipSell);
        }
        return profit;
    }

    //Time Complexity => O(n)
    //Space Complexity => O(n)
    int solveMem(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        //base case 
        if(index == n)
            return 0;

        if(limit == 0)
            return 0;
        
        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];

        int profit = INT_MIN;
        if(buy) {
            int canBuy = -prices[index] + solveMem(prices, index+1, 0, limit, dp);
            int skipBuy = 0 + solveMem(prices, index+1, 1, limit, dp);
            profit = max(canBuy, skipBuy);
        } else {
            int sell = +prices[index] + solveMem(prices, index+1, 1, limit-1, dp);
            int skipSell = 0 + solveMem(prices, index+1, 0, limit, dp);
            profit = max(sell, skipSell);
        }
        return dp[index][buy][limit] = profit;
    }

    //Time Complexity => O(n)
    //Space Complexity => O(n)
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index=n-1; index>=0; index--) {
            for(int buy=0; buy<=1; buy++) {
                for(int limit=1; limit<=2; limit++) {
                    int profit = INT_MIN;
                    if(buy) {
                        int canBuy = -prices[index] + dp[index+1][0][limit];
                        int skipBuy = 0 + dp[index+1][1][limit];
                        profit = max(canBuy, skipBuy);
                    } else {
                        int sell = +prices[index] + dp[index+1][1][limit-1];
                        int skipSell = 0 + dp[index+1][0][limit];
                        profit = max(sell, skipSell);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    
    //Time Complexity => O(n)
    //Space Complexity => O(1)
    int solveSO(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for(int index=n-1; index>=0; index--) {
            for(int buy=0; buy<=1; buy++) {
                for(int limit=1; limit<=2; limit++) {
                    int profit = INT_MIN;
                    if(buy) {
                        int canBuy = -prices[index] + next[0][limit];
                        int skipBuy = 0 + next[1][limit];
                        profit = max(canBuy, skipBuy);
                    } else {
                        int sell = +prices[index] + next[1][limit-1];
                        int skipSell = 0 + next[0][limit];
                        profit = max(sell, skipSell);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // //Recursive -> TLE
        // return solveRec(prices, 0, 1, 2);

        // //Recursion + Memoization
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solveMem(prices, 0, 1, 2, dp);

        // //Tabulation
        // return solveTab(prices);

        //Space-Optimization
        return solveSO(prices);
    }
};
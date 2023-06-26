//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(2^n);
    //Space Complexity => O(n) -> space of recursive call stack
    int solveRec(vector<int>& prices, int start, int end, int flag) {
        //base case
        if(start == end)
            return 0;

        int profit = 0;
        if(flag) {
            //we can buy or skip -> buy or skipBuy if flag = 1 else sell
            int buy = -prices[start] + solveRec(prices, start+1, end, 0);
            int skipBuy = 0 + solveRec(prices, start+1, end, 1);
            profit = max(buy, skipBuy);

        } else {
            //we can sell or skip -> sell or skipSell if flag = 0 else buy
            int sell = +prices[start] + solveRec(prices, start+1, end, 1);
            int skipSell = 0 + solveRec(prices, start+1, end, 0);
            profit = max(sell, skipSell);
        }
        return profit;
    }

    //Time Complexity => O(n)
    //Space Complexity => O(n)
    int solveMem(vector<int>& prices, int start, int end, int flag, vector<vector<int>>& dp) {
        //base case
        if(start == end)
            return 0;

        if(dp[start][flag] != -1)
            return dp[start][flag];

        int profit = 0;
        if(flag) {
            //we can buy or skip -> buy or skipBuy if flag = 1 else sell
            int buy = -prices[start] + solveMem(prices, start+1, end, 0, dp);
            int skipBuy = 0 + solveMem(prices, start+1, end, 1, dp);
            profit = max(buy, skipBuy);

        } else {
            //we can sell or skip -> sell or skipSell if flag = 0 else buy
            int sell = +prices[start] + solveMem(prices, start+1, end, 1, dp);
            int skipSell = 0 + solveMem(prices, start+1, end, 0, dp);
            profit = max(sell, skipSell);
        }
        return dp[start][flag] = profit;
    }

    //Time Complexity => O(n)
    //Space Complexity => O(n)
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));

        for(int start = n-1; start >=0; start--) {
            for(int flag = 0; flag<=1; flag++) {

                int profit = 0;
                if(flag) {
                    //we can buy or skip -> buy or skipBuy if flag = 1 else sell
                    int buy = -prices[start] + dp[start+1][0];
                    int skipBuy = 0 + dp[start+1][1];
                    profit = max(buy, skipBuy);

                } else {
                    //we can sell or skip -> sell or skipSell if flag = 0 else buy
                    int sell = +prices[start] + dp[start+1][1];
                    int skipSell = 0 + dp[start+1][0];
                    profit = max(sell, skipSell);
                }
                dp[start][flag] = profit;
            }
        }
        return dp[0][1];
    }

    //Time Complexity => O(n)
    //Space Complexity => O(1)
    int solveSO(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int start = n-1; start >=0; start--) {
            for(int flag = 0; flag<=1; flag++) {

                int profit = 0;
                if(flag) {
                    //we can buy or skip -> buy or skipBuy if flag = 1 else sell
                    int buy = -prices[start] + next[0];
                    int skipBuy = 0 + next[1];
                    profit = max(buy, skipBuy);

                } else {
                    //we can sell or skip -> sell or skipSell if flag = 0 else buy
                    int sell = +prices[start] + next[1];
                    int skipSell = 0 + next[0];
                    profit = max(sell, skipSell);
                }
                curr[flag] = profit;
            }
            next = curr;
        }
        return curr[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        // //Recursion
        // return solveRec(prices, 0, prices.size(), 1);

        // //Recursion + Memoization
        // vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        // return solveMem(prices, 0, prices.size(), 1, dp);

        // //Tabulation
        // return solveTab(prices);

        //Space-Optimization
        return solveSO(prices);

    }
};
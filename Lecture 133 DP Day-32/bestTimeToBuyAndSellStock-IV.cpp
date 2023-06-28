//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Time Complexity => O(n*k)
    //Space Complexity => O(k)
    int solveSOPrev(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        
        for(int index=n-1; index>=0; index--) {
            for(int buy=0; buy<=1; buy++) {
                for(int opeationNo=1; opeationNo<=k; opeationNo++) {
                    int profit = 0;
                    if(buy) {
                        int doBuy = -prices[index] + next[0][opeationNo];
                        int skipBuy = 0 + next[1][opeationNo];
                        profit = max(doBuy, skipBuy);
                    } else {
                        int doSell = +prices[index] + next[1][opeationNo-1];
                        int skipSell = 0 + next[0][opeationNo];
                        profit = max(doSell, skipSell);
                    }
                    curr[buy][opeationNo] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }

    //Time Complexity => O(2^nk)
    //Space Complexity => O(n*k) -> space used by maximum depth of recursive tree
    int solveRec(int k, vector<int>& prices, int index, int operationNo) { //Total opr = 2*k
        int n = prices.size();
        //base case
        if(index == n) return 0;
        if(operationNo == 2*k) return 0;

        int profit = INT_MIN;
        if((operationNo&1) == 0) {
            int doBuy = -prices[index] + solveRec(k, prices, index+1, operationNo+1);
            int skipBuy = 0 + solveRec(k, prices, index+1, operationNo);
            profit = max(doBuy, skipBuy);
        } else {
            int doSell = +prices[index] + solveRec(k, prices, index+1, operationNo+1);
            int skipSell = 0 + solveRec(k, prices, index+1, operationNo);
            profit = max(doSell, skipSell);
        }
        return profit;
    }

    //Time Complexity => O(n*k)
    //Space Complexity => O(n*k)
    int solveMem(int k, vector<int>& prices, int index, int operationNo, vector<vector<int>>& dp) { //Total opr = 2*k
        int n = prices.size();
        //base case
        if(index == n) return 0;
        if(operationNo == 2*k) return 0;

        if(dp[index][operationNo] != -1)
            return dp[index][operationNo];

        int profit = INT_MIN;
        if((operationNo&1) == 0) {
            int doBuy = -prices[index] + solveMem(k, prices, index+1, operationNo+1, dp);
            int skipBuy = 0 + solveMem(k, prices, index+1, operationNo, dp);
            profit = max(doBuy, skipBuy);
        } else {
            int doSell = +prices[index] + solveMem(k, prices, index+1, operationNo+1, dp);
            int skipSell = 0 + solveMem(k, prices, index+1, operationNo, dp);
            profit = max(doSell, skipSell);
        }
        return dp[index][operationNo] = profit;
    }

    //Time Complexity => O(n*k)
    //Space Complexity => O(n*k)
    int solveTab(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));

        for(int index = n-1; index>=0; index--) {
            for(int operationNo=2*k-1; operationNo>=0; operationNo--) {
                int profit = INT_MIN;
                if( (operationNo&1) == 0 ) {
                    int doBuy = -prices[index] + dp[index+1][operationNo+1];
                    int skipBuy = 0 + dp[index+1][operationNo];
                    profit = max(doBuy, skipBuy);
                } else {
                    int doSell = +prices[index] + dp[index+1][operationNo+1];
                    int skipSell = 0 + dp[index+1][operationNo];
                    profit = max(doSell, skipSell);
                }
                dp[index][operationNo] = profit;
            }
        }
        return dp[0][0];
    }

    //Time Complexity => O(n*k)
    //Space Complexity => O(k)
    int solveSO(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for(int index = n-1; index>=0; index--) {
            for(int operationNo=2*k-1; operationNo>=0; operationNo--) {
                int profit = INT_MIN;
                if( (operationNo&1) == 0 ) {
                    int doBuy = -prices[index] + next[operationNo+1];
                    int skipBuy = 0 + next[operationNo];
                    profit = max(doBuy, skipBuy);
                } else {
                    int doSell = +prices[index] + next[operationNo+1];
                    int skipSell = 0 + next[operationNo];
                    profit = max(doSell, skipSell);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        
        // return solveSOPrev(k, prices);


        // //Recursive solution
        // return solveRec(k, prices, 0, 0);

        // //Memoization+Recurison
        // int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2*k+1, -1));
        // return solveMem(k, prices, 0, 0, dp);

        // //Tabulation
        // return solveTab(k, prices);

        //Space-Optimization
        return solveSO(k, prices);
    }
};
//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091
//Time Complexity will be O(X*N) where X = total amount and N = no. of coins
//Space Complexity will be O(X) where X = amount

#include <bits/stdc++.h> 
using namespace std;

//Tabulation-> Bottom-Up Approach
int solveTab(vector<int> &num, int x) {
    //step-1 : Create a dp array
    vector<int> dp(x+1, INT_MAX);

    //step-2
    dp[0] = 0;

    //step-3
    for(int i=1; i<=x; i++) {
        for(int j=0; j<num.size(); j++) {
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX) {
                dp[i] = min( dp[i], 1+dp[i-num[j]] );
            }
        }
    }
    if(dp[x] == INT_MAX)
        return -1;
    else
        return dp[x];    
}

int minimumElements(vector<int> &num, int x)
{
    //Bottom-Up Approach (Tabulation)
    return solveTab(num, x);
}
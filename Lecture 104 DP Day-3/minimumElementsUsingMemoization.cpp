//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091
//Time Complexity will be O(X*N) where X = total amount and N = no. of coins
//Space Complexity will be O(X) where X = amount


#include <bits/stdc++.h> 
using namespace std;

//Recursion Solution with TLE
int solveRec(vector<int> &num, int x) {
    //base case 
    if(x == 0)
        return 0;
    
    if(x < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for(int i=0; i<num.size(); i++) {
        int ans = solveRec(num, x-num[i]);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }
    return mini;
}

//Recursion + Memoization Approach -> Top-Down Approach
int solveMem(vector<int>& num, int x, vector<int>& dp) {

    if(x == 0)
        return 0;
    if(x < 0)
        return INT_MAX;

    //step-3
    if(dp[x] != -1) 
        return dp[x];

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++) {
        int ans = solveMem(num, x-num[i], dp);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans); //1-added here for num[i] 
    }
    //step-2
    dp[x] = mini;
    return mini;
}

int minimumElements(vector<int> &num, int x)
{

    // //Recursion 
    // int result = solveRec(num, x);
    // if(result == INT_MAX) {
    //     return -1;
    // }
    // else {
    //     return result;
    // }


    //Top-Down Approach(using Memoization + Recursion)
    //step-1
    vector<int>dp(x+1, -1);

    int ans = solveMem(num , x, dp);
    if(ans == INT_MAX)
        return -1;
    else 
        return ans;

}
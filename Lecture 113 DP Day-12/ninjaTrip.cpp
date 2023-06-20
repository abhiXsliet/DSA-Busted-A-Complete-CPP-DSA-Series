//https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776

#include <bits/stdc++.h>
using namespace std;

//Recursive Solution
//Time Complexity will be Exponential O(3^n) (i.e.,3-calls for each are going recursively)
int solveRec(int n, vector<int>& days, vector<int>& cost, int index) {
    //base case
    if(index >= n)
        return 0;
    
    //day-1 pass
    int choice1 = cost[0] + solveRec(n, days, cost, index+1);

    //day-7 pass
    int i ;
    for(i=index; i<n && days[i] < days[index]+7; i++);
    int choice2 = cost[1] + solveRec(n, days, cost, i);

    //day-30 pass
    for(i=index; i<n && days[i] < days[index]+30; i++);
    int choice3 = cost[2] + solveRec(n, days, cost, i);

    return min(choice1, min(choice2, choice3));
}

//Time Complexity => O(1)
//Space Complexity => O(N)
int solveMem(int n, vector<int>& days, vector<int>& cost, int index, vector<int>& dp) {
    //base case
    if(index >= n)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];

    //day-1 pass
    int choice1 = cost[0] + solveMem(n, days, cost, index+1, dp);

    //day-7 pass
    int i;
    for(i=index; i<n && days[i]<days[index]+7; i++);
    int choice2 = cost[1] + solveMem(n, days, cost, i, dp);

    //day-30 pass
    for(i=index; i<n && days[i]<days[index]+7; i++);
    int choice3 = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(choice1, min(choice2, choice3));
    return dp[index];
}

//Time Complexity => O(N)
//Space Complexity => O(N)
int solveTab(int n, vector<int>& days, vector<int>& cost) {
    //step-1: create dp-array
    vector<int> dp(n+1, INT_MAX);

    //step-2: Base case analysis
    dp[n] = 0;

    //step-3: Handle remaining cases
    for(int k=n-1; k>=0; k--) {
        //day-1 pass
        int choice1 = cost[0] + dp[k+1];

        //day-7 pass
        int i;
        for(i=k; i<n && days[i] < days[k]+7; i++);
        int choice2 = cost[1] + dp[i];

        //day-30 pass
        for(i=k; i<n && days[i] < days[k]+30; i++);
        int choice3 = cost[2] + dp[i];

        dp[k] = min(choice1, min(choice2, choice3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{   
    // return solveRec(n, days, cost, 0);

    // //Recursion+Memoization
    // vector<int> dp(n+1, -1);
    // return solveMem(n, days, cost, 0, dp);

    //Tabulation
    return solveTab(n, days, cost);

}
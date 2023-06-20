//https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

//Time Complexity => O(2^n)
//Space Complexity => O(n)
int solveRec(vector<int>& weight, vector<int>& value, int index, int maxWeight) {
	//base case
	//if there is a single item available
	if(index == 0) {
		//check it's weight for the capacity limit of knapsack
		if(weight[0] <= maxWeight) {
			return value[0];
		} else {
			return 0;
		}
	}

	int include = 0;
	if(weight[index] <= maxWeight) 
		include = value[index] + solveRec(weight, value, index-1, maxWeight-weight[index]);

	int exclude = 0 + solveRec(weight, value, index-1, maxWeight);

	int ans = max(exclude, include);
	return ans;
}

//Time Complexity => O(N*W)
//Space Complexity => O(N*W) 
int solveMem(vector<int>& weight, vector<int>& value, int index, 
			int maxWeight, vector<vector<int>>& dp) {
	//base case
	if(index == 0) {
		if(weight[0] <= maxWeight) 
			return value[0];
		else 
			return 0;
	}

	//step-3
	if(dp[index][maxWeight] != -1)
		return dp[index][maxWeight];

	int include = 0;
	if(weight[index] <= maxWeight) {
		include = value[index] + solveMem(weight, value, index-1, maxWeight-weight[index], dp);
	}
	int exclude = 0 + solveMem(weight, value, index-1, maxWeight, dp);
	
	dp[index][maxWeight] = max(exclude, include);
	return dp[index][maxWeight];
}

//Time Complexity => O(N*W)
//Space Complexity => O(N*W)
int solveTab(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
	
	//step-1: creation of 2-D Array
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

	//step-2: analyse the base case
	for(int w = weight[0]; w <= maxWeight; w++) {
		if(weight[0] <= maxWeight)
			dp[0][w] = value[0];
		else
			dp[0][w] = 0;
	}

	//step-3: run loop for the remaining cases
	for(int index = 1; index<n; index++) {
		for(int w = 0; w <= maxWeight; w++) {

			int include = 0;
			if(weight[index] <= w)
				include = value[index] + dp[index-1][w-weight[index]];
			
			int exclude = 0 + dp[index-1][w];

			dp[index][w] = max(include, exclude);	
		}
	}
	return dp[n-1][maxWeight];
}


//Time Complexity => O(N*W)
//Space Complexity => O(maxWeight)
int solveTabSO(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
	
	//step-1 : 
	vector<int> prev(maxWeight+1, 0);
	vector<int> curr(maxWeight+1, 0);

	//step-2: Analyse the base case
	for(int w = weight[0]; w <= maxWeight; w++) {
		if(weight[0] <= maxWeight)
			prev[w] = value[0];
		else	
			prev[w] = 0;
	}

	//step-3: take care of remaining recursive calls
	for(int i=1; i<n; i++) {
		for(int w=0; w<=maxWeight; w++) {
			int include = 0;
			if(weight[i] <= w) 
				include = value[i] + prev[w-weight[i]];

			int exclude = 0 + prev[w];

			curr[w] = max(include, exclude);
		}
		prev = curr;
	}
	return prev[maxWeight];
}

//Time Complexity => O(N*W)
//Space Complexity => O(maxWeight)
int solveTabSO2(vector<int>& weight, vector<int>& value, int n, int maxWeight) {

	//Step-1: 
	vector<int> curr(maxWeight+1, 0);

	//Step-2:
	for(int w = weight[0]; w<=maxWeight; w++) {
		if(weight[0] <= maxWeight) 
			curr[w] = value[0];
		else 
			curr[w] = 0;
	}

	//step-3:
	for(int i=1; i<n; i++) {
		for(int w=maxWeight; w>=0; w--) {
			
			int include = 0;
			if(weight[i] <= w)
				include = value[i] + curr[w-weight[i]];
			
			int exclude = 0 + curr[w];

			curr[w] = max(include, exclude);
		}
	}
	return curr[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// return solveRec(weight, value, n-1, maxWeight);

	// //Recursion + Memoization
	// //step-1
	// vector<vector<int> > dp(n, vector<int>(maxWeight+1, -1));
	// return solveMem(weight, value, n-1, maxWeight, dp);


	//Tabulation-> Bottom Up
	// return solveTab(weight, value, n, maxWeight);


	//Space-Optimisation -> O(2*N)
	// return solveTabSO(weight, value, n, maxWeight);


	//Space-Optimisation -> O(N)
	return solveTabSO2(weight, value, n, maxWeight);

}


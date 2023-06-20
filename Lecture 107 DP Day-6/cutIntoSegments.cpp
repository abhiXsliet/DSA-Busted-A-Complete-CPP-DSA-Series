//https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651

#include<bits/stdc++.h>
using namespace std;

//Time Complexity will be exponential(3^N) and Space is constant
int solveRec(int n, int x, int y, int z) {
	//base case
	if(n == 0)
		return 0;
	if(n < 0) 
		return INT_MIN;

	int a = solveRec(n-x, x, y, z) + 1;
	int b = solveRec(n-y, x, y, z) + 1;
	int c = solveRec(n-z, x, y, z) + 1;

	int ans = max(a, max(b, c));
	return ans;

}

//Time Complexity => O(N) 
//Space Complexity => O(N) + O(N) => space of recursion depth & of dp-array
int solveMem(int n, int x, int y, int z, vector<int>& dp) {
	//base case
	if(n == 0)
		return 0;
	if(n < 0) 
		return INT_MIN;

	//step-3
	if(dp[n] != -1)
		return dp[n];

	int a = solveMem(n-x, x, y, z, dp) + 1;
	int b = solveMem(n-y, x, y, z, dp) + 1;
	int c = solveMem(n-z, x, y, z, dp) + 1;

	//step-2
	dp[n] = max(a, max(b, c));
	return dp[n];
}

//Time Complexity => O(N)
//Space Complexity => O(N)
int solveTab(int n, int x, int y, int z) {
	
    // //step-1: creation of dp array
	// vector<int> dp(n+1, INT_MIN);
	// //step-2
	// dp[0] = 0;
	// //step-3
	// for(int i=1; i<=n; i++) {
	// 	if(i-x >= 0)
	// 		dp[i] = max(dp[i], dp[i-x] + 1) ;
	// 	if(i-y >= 0)
	// 		dp[i] = max(dp[i], dp[i-y] + 1) ;
	// 	if(i-z >= 0)
	// 		dp[i] = max(dp[i], dp[i-z] + 1) ;
	// }
	// //step-4	
	// return dp[n];
    

    //step-1: creation of dp array
	vector<int> dp(n+1, -1);
	
	//step-2
	dp[0] = 0;

	//step-3
	for(int i=1; i<=n; i++) {
		if(i-x >= 0 && dp[i-x] != -1)
			dp[i] = max(dp[i], dp[i-x] + 1) ;

		if(i-y >= 0 && dp[i-y] != -1)
			dp[i] = max(dp[i], dp[i-y] + 1) ;
			
		if(i-z >= 0 && dp[i-z] != -1)
			dp[i] = max(dp[i], dp[i-z] + 1) ;
	}
	//step-4	
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	
    // //Recursive Solution
	// int ans = solveRec(n, x, y, z);
	// if(ans < 0)
	// 	return 0;
	// else
	// 	return ans;


	// //Recursion + Memoization -> Top-Down Approach
	// //step-1: creation of dp vector
	// vector<int> dp(n+1, -1);
	// int ans = solveMem(n, x, y, z, dp);
	// if(ans < 0)	 
	// 	return 0;
	// else
	// 	return ans;


	//Tabulation -> Bottom-Up Approach
	int ans = solveTab(n, x, y, z);
	if(ans < 0)
		return 0;
	else
		return ans;

}
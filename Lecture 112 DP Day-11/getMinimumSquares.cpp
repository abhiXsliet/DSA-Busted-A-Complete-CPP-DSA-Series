//https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int solveRec(int n) {
        //base case
        if(n == 0)
            return 0;   
        
        int ans = n;
        for(int i=1; i*i <= n; i++) {
            ans = min(ans, 1+solveRec(n-i*i));
        }
        return ans;
    }
    
    int solveMem(int n, vector<int>& dp) {
        //base case
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
            
        int ans = n;
        for(int i=1; i*i <= n; i++) {
            ans = min(ans, 1+solveMem(n-i*i, dp));
        }
        dp[n] = ans;
        return ans;
    }
    
    int solveTab(int n) {
        //step-1
        vector<int> dp(n+1, INT_MAX);
        
        //step-2: analyse the base case
        dp[0] = 0;
        
        //step-3: handle the remaining cases
        for(int i=1; i<=n; i++) {
            
            for(int j=1; j*j<=n; j++) {
                int temp = j*j;
                if(i-temp >= 0)    
                    dp[i] = min(dp[i], 1+dp[i-temp]);
            }
        }
        return dp[n];
    }
    
	public:
	int MinSquares(int n)
	{
	   // return solveRec(n);
	   
	   ////Recursion + Memoization -> Top-Down Approach
	   //vector<int> dp(n+1, -1);
	   //return solveMem(n, dp);
	   
	   //Tabulation -> Bottom-Up Approach
	   return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
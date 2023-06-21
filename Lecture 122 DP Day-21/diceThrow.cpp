//https://practice.geeksforgeeks.org/problems/dice-throw5349/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    //Time Complexity => exponential, O(face^dices)
    //Space Complexity => O(dices)
    long long int solveRec(int faces, int dices, int target) {
        //base case
        if(target < 0)
            return 0;
        if(target == 0 && dices != 0)
            return 0;
        if(dices == 0 && target != 0)
            return 0;
        if(target == 0 && dices == 0)
            return 1;
        
        long long ans = 0;
        for(int i=1; i<=faces; i++) {
            ans = ans + solveRec(faces, dices-1, target-i);
        }
        return ans;
    }

    //Time Complexity => O(N*X*M) where N = No. of dices, X = target, M = faces
    //Space Complexity => O(N*X)  where N = No. of dices, X = target
    long long int solveMem(int faces, int dices, int target, vector<vector<long long>>& dp) {
        //base case
        if(target < 0)
            return 0;
        if(target == 0 && dices != 0)
            return 0;
        if(dices == 0 && target != 0)
            return 0;
        if(target == 0 && dices == 0)
            return 1;
            
        if(dp[dices][target] != -1)
            return dp[dices][target];
        
        long long ans = 0;
        for(int i=1; i<=faces; i++) {
            ans = ans + solveMem(faces, dices-1, target-i, dp);
        }
        dp[dices][target] = ans;
        return dp[dices][target];
    }
    
    //Time Complexity => O(N*X*M) where N = No. of dices, X = target, M = faces
    //Space Complexity => O(N*X)  where N = No. of dices, X = target
    long long solveTab(int M, int N, int X) {
    
        vector<vector<long long> > dp(N+1, vector<long long>(X+1, 0));
        //after analysing base case
        dp[0][0] = 1;
        
        for(int dice=1; dice<=N; dice++) {
            for(int target=1; target<=X; target++) {
                long long ans = 0;
                for(int idx=1; idx<=M; idx++) {
                    
                    if(target-idx >= 0)
                        ans = ans+dp[dice-1][target-idx];
                }
                dp[dice][target] = ans;
            }
        }
        return dp[N][X];
    }
    
    //Time Complexity => O(N*X*M) where N = No. of dices, X = target, M = faces
    //Space Complexity => O(X)  where X = target
    long long solveSO(int M, int N, int X) {
    
        vector<long long> prev(X+1, 0);
        vector<long long> curr(X+1, 0);
        
        //after analysing base case
        prev[0] = 1;
        
        for(int dice=1; dice<=N; dice++) {
            for(int target=1; target<=X; target++) {
                long long ans = 0;
                for(int idx=1; idx<=M; idx++) {
                    
                    if(target-idx >= 0)
                        ans = ans+prev[target-idx];
                }
                curr[target] = ans;
            }
            prev = curr;
        }
        return prev[X];
    }
    
  public:
    long long noOfWays(int M , int N , int X) {
        // //Recursive Approach -> TLE
        // return solveRec(M, N, X);
        
        // //Top-Down Approach
        // vector<vector<long long>>dp(N+1, vector<long long>(X+1, -1));
        // return solveMem(M, N, X, dp);
        
        // //Bottom-Up Approach
        // return solveTab(M, N, X);
        
        //Space Optimization
        return solveSO(M, N, X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
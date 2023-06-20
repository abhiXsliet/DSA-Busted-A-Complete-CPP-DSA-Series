//https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    //Time Complexity => Exponential
    int solveRec(int i, int j, vector<vector<int>>&mat, int &maxi) {
        //base case
        if(i >= mat.size() || j >= mat[0].size())
            return 0;
            
        //recursive calls
        int right = solveRec(i, j+1, mat, maxi);
        int diagonal = solveRec(i+1, j+1, mat, maxi);
        int down = solveRec(i+1, j, mat, maxi);
        
        if(mat[i][j] == 1) {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
            
        } else {
            return 0;
        }
        
    }
    
    //Time Complexity => O(1) and Space Complexity => O(1)
    int solveMem(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&dp, int &maxi) {
        //base case
        if(i >= mat.size() || j >= mat[0].size())
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        //recursive calls
        int right = solveMem(i, j+1, mat, dp, maxi);
        int diagonal = solveMem(i+1, j+1, mat, dp, maxi);
        int down = solveMem(i+1, j, mat, dp, maxi);
        
        if(mat[i][j] == 1) {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
            
        } else {
            return dp[i][j] = 0;
        }
        
    }
    
    //Time Complexity => O(1) and Space Complexity => O(n*m) where n and m = no. of rows and columns respectively
    int solveTab(vector<vector<int>> &mat, int &maxi) {
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>>dp(row+1, vector<int>(col+1, 0));
        
        for(int i=row-1; i>=0; i--) {
            for(int j=col-1; j>=0; j--) {
                
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j] == 1) {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    
    //Space Complexity => O(m) where m = no. of columns
    int solveSO(vector<vector<int>> &mat, int &maxi) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(col+1, 0);
        vector<int> next(col+1, 0);
        
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--) {
                
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1) {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                    
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
    
    //Space Complexity => O(1)
    int solveSO2(int row, int col, vector<vector<int>> &mat, int &maxi) {
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                
                if(i>0 && j>0 && mat[i][j]){
                    int right = mat[i][j-1];
                    int diagonal = mat[i-1][j-1];
                    int down = mat[i-1][j];
                    
                    mat[i][j] = 1+ min(right, min(diagonal, down));
                }                    
                maxi = max(maxi, mat[i][j]);
            }
        }
        return maxi;
    }
    
    //Space Complexity => O(1)
    int solveSO3(vector<vector<int>> &mat, int &maxi) {
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(50, 0);
        vector<int> next(51, 0);
        
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--) {
                
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1) {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                    
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
    
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // int maxi = 0;
        // solveRec(0, 0, mat, maxi);
        // return maxi;
        
        
        // //Memoization Aproach
        // int maxi = 0;
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // solveMem(0, 0, mat, dp, maxi);
        // return maxi;
        
        // //Tabulation Approach
        // int maxi = 0;
        // solveTab(mat, maxi);
        // return maxi;
        
        //Space Optimization
        // int maxi = 0;
        // solveSO(mat, maxi);
        // return maxi;
        
        // //Space Optimization-2
        // int maxi = 0;
        // solveSO2(n, m, mat, maxi);
        // return maxi;
        
        //Space Optimization-3
        int maxi = 0;
        solveSO3(mat, maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
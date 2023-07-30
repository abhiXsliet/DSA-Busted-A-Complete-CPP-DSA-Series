//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>>& m){
        if((x >= 0 && x<n) && (y >= 0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
            return true;
        }else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m, int n, int x, int y, string path, vector<vector<int>>visited, vector<string>& ans) {
        
        //you have reach x, y here
        
        //base case
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return ;
        }
        
        visited[x][y] = 1;
        
        //4-choices - D, L, R, U
        
        //Down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, n, visited, m)) {
            path.push_back('D');
            
            //R.R
            solve(m, n, newx, newy, path, visited, ans);
            
            //backtrack
            path.pop_back();
        }
        
        //left
        newx = x;
        newy = y-1;
        
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('L');
            
            //R.R
            solve(m, n, newx, newy, path, visited, ans);
            path.pop_back();
        }
        
        //right
        newx = x;
        newy = y+1;
        
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('R');
            
            solve(m, n, newx, newy, path, visited, ans);
            
            path.pop_back();
        }
        
        //UP
        newx = x-1;
        newy = y;
        
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('U');
            
            solve(m, n, newx, newy, path, visited, ans);
            
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
    
        vector<string> ans;

        if(m[0][0] == 0){
            return ans;
        }
        
        int srcx = 0;
        int srcy = 0;
        
        vector<vector<int>>visited = m;        
        
        //initialising with zero
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
        string path = "";
        
        solve(m, n, srcx, srcy, path, visited, ans);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

    

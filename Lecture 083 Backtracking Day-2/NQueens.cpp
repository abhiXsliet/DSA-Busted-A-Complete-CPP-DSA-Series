//https://www.codingninjas.com/codestudio/problems/n-queens_759332

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {

    //straight movement
    int x = row;
    int y = col;
    while(y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
    }

    //diagonal movement in downward-left
    x = row;
    y = col;
    while(x<n && y>=0) {
        if(board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }

    //diagonal movement in upward-left
    x = row;
    y = col;
    while(x>=0 && y>=0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }
    return true;
}

void addSolution(vector<vector<int>>& board, vector<vector<int>>& ans, int n) {
    
    vector<int>temp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, vector<vector<int>>& board, vector<vector<int>>& ans, int n) {
    //base case
    if(col == n) {
        //store answer & return
        addSolution(board, ans, n);
        return;
    }

    //solving 1st-case and rest recursion will take care
    for(int row=0; row<n; row++) {
        if(isSafe(row, col, board, n)) {
            //action->if placing is safe
            board[row][col] = 1;

            //recursive call
            solve(col+1, board, ans, n);

            //backtracking logic
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {

    //board
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>>ans;
    int col = 0;
    solve(col, board, ans, n);
    
    return ans;
}
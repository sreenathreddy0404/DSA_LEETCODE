//problem link: https://leetcode.com/problems/n-queens/description/
// Approach: Backtracking

// Time Complexity: O(N.N!)
// Space Complexity: O(N^2)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> ans;
    bool canFit(int n,vector<string> &board,int row,int col){

        //row check
        for(int i=0;i<n;i++){
            if(board[row][i] == 'Q')return false;
        }

        //diagonal check
        for(int i=1;i<n;i++){
            //upper left
            if(row-i>=0 && col-i>=0)
                if(board[row-i][col-i] == 'Q')return false;

            //lower right
            if(row+i<n && col+i<n)
                if(board[row+i][col+i] == 'Q')return false;

            //lower left
            if(row+i<n && col-i>=0)
                if(board[row+i][col-i] == 'Q')return false;
            
            //upper right
            if(row-i>=0 && col+i<n)
                if(board[row-i][col+i] == 'Q')return false;
        }

        return true;
    }
    void solve(int n,vector<string> &board,int col){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0;row<n;row++){
            if(canFit(n,board,row,col)){
                board[row][col] = 'Q';
                solve(n,board,col+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));

        solve(n,board,0);

        return ans;
    }
};
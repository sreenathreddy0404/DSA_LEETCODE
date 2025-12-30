//problem link : https://leetcode.com/problems/magic-squares-in-grid/description/
// Time Complexity: O(m*n) where m is number of rows and n is number of
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMagicSquare(vector<vector<int>>&grid,int row,int col){
        vector<int> num(9,0);
        vector<int> rows(3,0);
        vector<int> cols(3,0);
        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2;j++){
                rows[i-row] += grid[i][j];
                cols[j-col] += grid[i][j];
                if(grid[i][j]>9 || grid[i][j] == 0)return false;
                num[grid[i][j]-1]++;
                if(num[grid[i][j]-1] > 1)return false;
            }
        }
        int d1 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        int d2 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        if(d1 != d2)return false;
        for(int i=0;i<3;i++){
            if(rows[i] != d1 || cols[i] != d1)return false;
        }
        

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;
        for(int i=0;i<rows-2;i++){
            for(int j=0;j<cols-2;j++){
                if(isMagicSquare(grid,i,j))count++;
            }
        }

        return count;
    }
};
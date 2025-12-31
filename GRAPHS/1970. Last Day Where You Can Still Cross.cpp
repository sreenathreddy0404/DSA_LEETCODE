// problem link : https://leetcode.com/problems/last-day-where-you-can-still-cross/description
// Time Complexity : O(log(m * n) * m * n)
// Space Complexity : O(m * n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows;
    int cols;
    bool dfs(int row,int col,vector<vector<int>> &island){
        if(row<0 || col<0 || row >= rows || col >= cols || island[row][col] == 1)return false;
        if(row == rows-1)return true;
        island[row][col] = 1;

        if(dfs(row,col+1,island))return true;
        if(dfs(row,col-1,island))return true;
        if(dfs(row-1,col,island))return true;
        if(dfs(row+1,col,island))return true;

        return false;
    }

    bool check(vector<vector<int>> &cells,int mid){
         vector<vector<int>> island(rows,vector<int>(cols,0));

         for(int i=0;i<=mid;i++){
            island[cells[i][0]-1][cells[i][1]-1] = 1;
         }

         for(int i=0;i<cols;i++){
            if(island[0][i] == 0 && dfs(0,i,island))return true;
         }

         return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        rows = row;
        cols = col;

        int l = 0;
        int h = cells.size()-1;
        int ans = 1;
        while(l<=h){
            int m = l+(h-l)/2;

            if(check(cells,m)){
                ans = m;
                l = m+1;
            }else{
                h = m-1;
            }
        }

        return ans+1;
    }
};
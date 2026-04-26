// Problem Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    vector<vector<int>> dirs = {{0,-1},{-1,0},{0,1},{1,0}};

    bool dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &visited,int pi,int pj){
        visited[i][j] = true;

        for(auto &d:dirs){
            int ni = i+d[0];
            int nj = j+d[1];

            if(ni<0 || nj<0 || ni>=n || nj>=m)continue;
            if(pi == ni && pj == nj)continue;
            if(grid[ni][nj] != grid[i][j])continue;
            
            if(visited[ni][nj])return true;

            if(dfs(ni,nj,grid,visited,i,j))return true;
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j])continue;
                if(dfs(i,j,grid,visited,-1,-1))return true;
            }
        }

        return false;
    }
};
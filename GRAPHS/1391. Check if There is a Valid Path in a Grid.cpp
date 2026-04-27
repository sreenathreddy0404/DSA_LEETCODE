// Problem Link : https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;

    vector<vector<vector<int>>> dir = {
        {},
        {{0,-1},{0,1}},
        {{-1,0},{1,0}},
        {{0,-1},{1,0}},
        {{0,1},{1,0}},
        {{0,-1},{-1,0}},
        {{-1,0},{0,1}}
    };

    bool check(int i, int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    bool isConnected(int from_i, int from_j, int to_i, int to_j, vector<vector<int>>& grid){
        for(auto d : dir[grid[to_i][to_j]]){
            int ni = to_i + d[0];
            int nj = to_j + d[1];
            if(ni == from_i && nj == from_j) return true;
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){
            auto it = q.front();
            int i = it.first;
            int j = it.second;
            q.pop();

            if(i == n-1 && j == m-1) return true;

            for(auto d : dir[grid[i][j]]){
                int ni = i + d[0];
                int nj = j + d[1];

                if(check(ni,nj) && !visited[ni][nj] && isConnected(i,j,ni,nj,grid)){
                    visited[ni][nj] = true;
                    q.push({ni,nj});
                }
            }
        }

        return false;
    }
};
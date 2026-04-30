// Problem Link : https://leetcode.com/problems/maximum-path-score-in-a-grid/
// Time Complexity : O(m*n*k)
// Space Complexity : O(m*n*k)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int k) {
        if (i >= n || j >= m) return -1e8;

        int cost = (grid[i][j] == 2) ? 1 : grid[i][j];
        if (k < cost) return -1e8;

        if (i == n-1 && j == m-1) {
            return grid[i][j];
        }

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int right = solve(grid, i, j+1, k - cost);
        int down  = solve(grid, i+1, j, k - cost);

        int best = max(right, down);
        if (best < 0) return dp[i][j][k] = -1e8;

        return dp[i][j][k] = best + grid[i][j];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

        int ans = solve(grid, 0, 0, k);
        return (ans < 0) ? -1 : ans;
    }
};
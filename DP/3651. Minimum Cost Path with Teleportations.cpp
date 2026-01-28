//problem link: https://leetcode.com/problems/minimum-cost-path-with-teleportations/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef pair<int, int> PII;
    unordered_map<int, vector<PII>> um;
    int m, n;

    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>> &grid, int i, int j, int k)
    {
        if (i == m - 1 && j == n - 1)
        {
            return 0;
        }

        // out of bounds
        if (i >= m || j >= n)
            return 1e8;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int right = INT_MAX;
        int bottom = INT_MAX;
        if (j + 1 < n)
            right = grid[i][j + 1] + solve(grid, i, j + 1, k);
        if (i + 1 < m)
            bottom = grid[i + 1][j] + solve(grid, i + 1, j, k);

        int teleport = INT_MAX;
        if (k > 0)
        {
            for (auto p : um[i * n + j])
            {
                teleport = min(teleport, solve(grid, p.first, p.second, k - 1));
            }
        }

        return dp[i][j][k] = min({right, bottom, teleport});
    }

    int minCost(vector<vector<int>> &grid, int k)
    {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int x = 0; x < m; x++)
                {
                    for (int y = 0; y < n; y++)
                    {
                        if (grid[x][y] <= grid[i][j] && !(x == i && y == j))
                        {
                            um[i * n + j].push_back({x, y});
                        }
                    }
                }
            }
        }

        // for(auto v:um){
        //     cout<<v.first<<" -> ";
        //     for(auto p:v.second){
        //         cout<<"{"<<p.first<<","<<p.second<<"}"<<",";
        //     }
        //     cout<<endl;
        // }

        return solve(grid, 0, 0, k);
    }
};

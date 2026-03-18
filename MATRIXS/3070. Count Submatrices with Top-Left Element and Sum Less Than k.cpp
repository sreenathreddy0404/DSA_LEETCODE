// Problem Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
// Time Complexity: O(n*m)
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i > 0)grid[i][j] += grid[i-1][j];
                if(j > 0)grid[i][j] += grid[i][j-1];
                if(i > 0 && j > 0)grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k)count++;
            }
        }

        return count;
    }
};
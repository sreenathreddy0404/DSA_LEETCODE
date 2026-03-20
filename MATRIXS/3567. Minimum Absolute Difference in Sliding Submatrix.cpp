// Problem link : https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/
// Time Complexity: O(n * m * k * k)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,int k){
        vector <int> ans;
        for(int a=i;a<i+k;a++){
            for(int b=j;b<j+k;b++){
                ans.push_back(grid[a][b]);
            }
        }
        sort(ans.begin(),ans.end());
        int minAbsDiff = INT_MAX;

        for(int a = 1;a<k*k;a++){
            if(ans[a] == ans[a-1])continue;
            int diff = abs(ans[a] - ans[a-1]);
            minAbsDiff = min(minAbsDiff,diff);
        }
        return minAbsDiff == INT_MAX?0:minAbsDiff;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n-k+1,vector<int>(m-k+1));

        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                res[i][j] = helper(grid,i,j,k);
            }
        }

        return res;
    }
};
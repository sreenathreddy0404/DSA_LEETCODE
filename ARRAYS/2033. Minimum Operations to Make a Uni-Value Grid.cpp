// Problem link : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/
// Time complexity : O(m*n log(m*n))
// Space complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem = grid[0][0]%x;

        int n = grid.size();
        int m = grid[0].size();

        vector<int> arr;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]%x != rem)return -1;
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(),arr.end());

        int ans = 0;
        int mid = arr[(m*n)/2];
        for(int i=0;i<(m*n);i++){
            ans += abs(arr[i]-mid)/x;
        } 

        return ans;
    }
};
// Problem link : https://leetcode.com/problems/equal-sum-grid-partition-i/
// Time Complexity: O(n * m)
// Space Complexity: O(n + m)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> rowSum(n,0);
        vector<long long> colSum(m,0);
        long long totalSum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                totalSum += grid[i][j];
            }
        }

        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += rowSum[i];

            if(2*sum == totalSum)return true;
            if(2*sum > totalSum)break;
        }

        sum = 0;
        for(int j=0;j<m;j++){
            sum += colSum[j];

            if(2*sum == totalSum)return true;
            if(2*sum > totalSum)break;
        }
        return false;
    }
};
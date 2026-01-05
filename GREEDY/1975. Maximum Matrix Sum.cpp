// Problem Link: https://leetcode.com/problems/maximum-matrix-sum/
// Time Complexity: O(n*m)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool flag = false;
        int n = matrix.size();
        int m = matrix[0].size();
        int small = INT_MAX;
        long long sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                small = min(small,abs(matrix[i][j]));
                if(matrix[i][j] < 0){
                    flag = !flag;
                }
                sum += abs(matrix[i][j]);
            }
        }

        if(flag){
            sum -= 2*small;
        }

        return sum;
    }
};
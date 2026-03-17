//problem link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/
// Time complexity : O(max(n*m , n*log(n)) where n is the number of rows m is the number of columns
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 1+matrix[i-1][j];
                }
            }
        }

        int maxArea = 0;

        for(int i=0;i<n;i++){
            sort(matrix[i].rbegin(),matrix[i].rend());
            int area = 0;
            for(int j=0;j<m;j++){
                area = max(area,matrix[i][j]*(j+1));
            }
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};
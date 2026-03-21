// Problem link : https://leetcode.com/problems/flip-square-submatrix-vertically/
// Time Complexity: O(k * k)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0;i<k/2;i++){
            int x1 = x+i;
            int x2 = x+k-i-1;
            for(int j=y;j<y+k;j++){
                swap(grid[x2][j],grid[x1][j]);
            }
        }
        return grid;
    }
};
// Problem link : https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Time Complexity: O(n * m)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            if(mat == target)return true;
            rotate(mat);
        }

        return false;
    }
};
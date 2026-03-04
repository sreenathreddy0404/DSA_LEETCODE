// Problem Link : https://leetcode.com/problems/special-positions-in-a-binary-matrix/description
// Time Complexity : O(M*N)
// Space Complexity : O(M + N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> rows(n);
        vector<int> cols(m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)count++;
            }
        }

        return count;
    }
};
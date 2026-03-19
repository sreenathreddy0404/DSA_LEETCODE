// Problem link : https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
// Time Complexity: O(n * m)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> prefix(n,vector<int>(m,0));
        vector<bool> seenChar(m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != '.')seenChar[j]=true;
                if(j>0)seenChar[j] = seenChar[j] | seenChar[j-1];
                if(grid[i][j] == 'X')prefix[i][j]++;
                else if(grid[i][j] == 'Y')prefix[i][j]--;

                if(i>0) prefix[i][j] += prefix[i-1][j];
                if(j>0) prefix[i][j] += prefix[i][j-1];
                if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];

                if(prefix[i][j] == 0 && seenChar[j]) ans++;
            }
        }

        return ans;
    }
};
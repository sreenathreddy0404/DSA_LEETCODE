//Problem link: https://leetcode.com/problems/maximal-rectangle/
//Time complexity: O(n*m)
//Space complexity: O(n*m)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> mat(n,vector<int>(m,0));

        //find width row wise
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j == 0){
                    if(matrix[i][j] == '1')mat[i][j] = 1;
                }else{
                    if(matrix[i][j] == '1'){
                        mat[i][j] = 1+mat[i][j-1];
                    }
                }
            }
        }

        //find height col wise
        int ans = 0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                int width = mat[i][j];

                //move upwards
                for(int k=i;k>=0 && mat[k][j]>0;k--){
                    int height = i-k+1;
                    width = min(width,mat[k][j]);
                    ans = max(ans,width*height);
                }
            }
        }

        return ans;
    }
};
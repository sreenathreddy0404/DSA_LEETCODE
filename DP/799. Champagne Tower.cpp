// Problem Link : https://leetcode.com/problems/champagne-tower/description/
// Time Complexity : O(N*M)
// Space Complexity : O(100 * 100)

#include <bits/stdc++.h>
using namespace std;


//Approach : recurssion + dp
class Solution {
public:
    double dp[101][101];
    double solve(int poured,int i,int j){
        if(i < 0 || i < j || j < 0)return 0;
        if(i == 0 && j == 0)return poured;

        if(dp[i][j] != -1)return dp[i][j];
        double glass1 = (solve(poured,i-1,j-1)-1)/2.0;
        double glass2 = (solve(poured,i-1,j)-1)/2.0;
        if(glass1 < 0)glass1 = 0;
        if(glass2 < 0)glass2 = 0;

        return dp[i][j] = glass1+glass2;

    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                dp[i][j] = -1.0;
            }
        }
        return min(1.0,solve(poured,query_row,query_glass));
    }
};
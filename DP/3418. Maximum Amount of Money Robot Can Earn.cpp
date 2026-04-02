// Problem link : https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/

#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N*M*2)
// Space Complexity: O(N*M*2)

class Solution {
public:
    int dp[501][501][3];
    bool vis[501][501][3];

    int helper(vector<vector<int>>& coins,int i,int j,int power){
        if(i == 0 && j == 0){
            if(coins[i][j] < 0 && power > 0) return 0;
            return coins[i][j];
        }

        if(i < 0 || j < 0) return INT_MIN/2;

        if(vis[i][j][power]) return dp[i][j][power];

        int res = INT_MIN;

        // Use power if negative
        if(coins[i][j] < 0 && power > 0){
            res = max(res, helper(coins,i-1,j,power-1));
            res = max(res, helper(coins,i,j-1,power-1));
        }

        // Don't use power
        res = max(res, coins[i][j] + helper(coins,i-1,j,power));
        res = max(res, coins[i][j] + helper(coins,i,j-1,power));

        vis[i][j][power] = true;
        return dp[i][j][power] = res;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        memset(vis,false,sizeof(vis));
        return helper(coins,coins.size()-1,coins[0].size()-1,2);
    }
};
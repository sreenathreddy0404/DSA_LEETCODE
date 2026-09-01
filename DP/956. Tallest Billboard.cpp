// problem link : https://leetcode.com/problems/tallest-billboard/
// time complexity : O(n*sum(heights));
// space compexity : O(n*sum(heights));

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[20][10001];
    int solve(vector<int>& rods, int i, int diff){
        if(i == n){
            if(diff == 0)return 0;
            return -1e5;
        }
        if(dp[i][diff+5000] != -1)return dp[i][diff+5000];
        //don't take in any rod
        int ignore = solve(rods,i+1,diff);

        //take to rod 1
        int addToRod1 = rods[i] + solve(rods,i+1,diff + rods[i]);

        //take to rod2
        int addToRod2 = rods[i] + solve(rods,i+1,diff - rods[i]);

        return dp[i][diff+5000] = max({ignore,addToRod1,addToRod2});
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        memset(dp,-1,sizeof(dp));
        return (solve(rods,0,0))/2;
    }
};
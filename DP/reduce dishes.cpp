// Problem Link: https://leetcode.com/problems/reducing-dishes/
#include <bits/stdc++.h>
using namespace std;
//Approach: Dynamic Programming (Top-Down with Memoization)
//Greedy solution in greedy floder
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& satisfaction,int i,int time){
        if(i == n)return 0;
        if(dp[i][time] != -1)return dp[i][time];

        int skip = solve(satisfaction,i+1,time);
        int take = time*satisfaction[i] + solve(satisfaction,i+1,time+1);

        return dp[i][time] = max(take,skip);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        n = satisfaction.size();
        dp.resize(n,vector<int>(n+1,-1));
        return solve(satisfaction,0,1);
    }
};
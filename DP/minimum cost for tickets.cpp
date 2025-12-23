//problem link : https://leetcode.com/problems/minimum-cost-for-tickets/

// Approach: Dynamic Programming (Bottom-Up)
// Time Complexity: O(N)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int>& days,vector<int>& costs,int i){
        if(i >= n)return 0;
        if(dp[i] != -1)return dp[i];
        int res = INT_MAX;
        //one day pass
        res = costs[0] + solve(days,costs,i+1);

        //7 days pass
        int next = lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
        res = min(res,costs[1] + solve(days,costs,next));

        //30 days pass
        next = lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
        res = min(res,costs[2] + solve(days,costs,next));
        return dp[i] = res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.resize(n,-1);
        return solve(days,costs,0);
    }
};
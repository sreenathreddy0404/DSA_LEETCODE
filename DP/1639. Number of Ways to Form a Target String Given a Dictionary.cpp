// Problem Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
// Time Complexity: O(k*m)
// Space Complexity: O(k*m)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m,k;
    vector<vector<int>> freq;
    int dp[1001][1001];
    int mod = 1e9+7;
    int solve(int i,int j,string &target){
        //i->target index
        //j->string in words index
        if(i == k)return 1;
        if(j == m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int nottaken = solve(i,j+1,target)%mod;

        int taken = (1LL*freq[target[i]-'a'][j] * solve(i+1,j+1,target))%mod;
        return dp[i][j] = (taken+nottaken)%mod;
    }
    int numWays(vector<string>& words, string target) {
        n = words.size();
        m = words[0].size();
        k = target.size();
        

        freq.resize(26,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                freq[words[i][j]-'a'][j]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,0,target);
    }
};
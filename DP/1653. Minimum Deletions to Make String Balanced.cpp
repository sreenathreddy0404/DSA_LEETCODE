// Greedy solution exists in greedy folder
// problem link : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description
// time complexity : O(N);
// space complexity : O(N);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[100000][2];
    int solve(string &s,int i,bool b){
        if(i == n)return 0;
        
        if(dp[i][b] != -1)return dp[i][b]; 
        int taken = INT_MIN;
        int nottaken = INT_MIN;
        if(!b && s[i] == 'a'){
            taken = 1+solve(s,i+1,b);
        }else if(s[i] == 'b'){
            taken = 1+solve(s,i+1,true);
            nottaken = solve(s,i+1,b);
        }else{
            nottaken = solve(s,i+1,b);
        }

        return dp[i][b] = max(taken,nottaken);
    }
    int minimumDeletions(string s) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return n-solve(s,0,false);
    }
};
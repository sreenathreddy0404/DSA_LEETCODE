//problem link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
//time complexity: O(m*n)
//space complexity: O(m*n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n1,n2;
    vector<vector<int>> dp;
    int solve(string &s1,string &s2,int i,int j){
        if(i < 0 || j < 0){
            int sum = 0;
            while(i >= 0){
                sum += s1[i];
                i--;
            }

            while(j >= 0){
                sum += s2[j];
                j--;
            }

            return sum;
        }

        if(dp[i][j] != -1)return dp[i][j];

        int res = INT_MAX;
        if(s1[i] != s2[j]){
            res = min({res,s1[i] + solve(s1,s2,i-1,j),s2[j] + solve(s1,s2,i,j-1)});
        }else{
            res = min(res,solve(s1,s2,i-1,j-1));
        }

        return dp[i][j] = res;
    }
    int minimumDeleteSum(string s1, string s2) {
        n1 = s1.size();
        n2 = s2.size();
        dp.resize(n1,vector<int>(n2,-1));
        return solve(s1,s2,n1-1,n2-1);
    }
};

//Tabulation approach
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1, 0));

        for(int i=1;i<=n1;i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }

        for(int j=1;j<=n2;j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int res = INT_MAX;
                if(s1[i-1] != s2[j-1]){
                    res = min({res,s1[i-1] + dp[i-1][j],s2[j-1] + dp[i][j-1]});
                }else{
                    res = min(res,dp[i-1][j-1]);
                }

                dp[i][j] = res;
            }
        }

        return dp[n1][n2];
    }
};
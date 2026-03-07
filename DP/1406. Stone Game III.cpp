// Problem link : https://leetcode.com/problems/stone-game-iii/description
// Time Complexity : O(N)
// Space Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[50001][2];
    int solve(vector<int>& stones,int i,int person){
        if(i == n)return 0;
        if(dp[i][person] != -1)return dp[i][person];

        int res = (person == 1)? INT_MIN:INT_MAX;

        int value = 0;
        for(int j=i;j<n && j<i+3;j++){
            value += stones[j];

            if(person == 1){
                res = max(res,value + solve(stones,j+1,0));
            }else{
                res = min(res,solve(stones,j+1,1));
            }
        }
        return dp[i][person] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int totalValue = 0;
        n = stoneValue.size();

        for(int i=0;i<n;i++){
            totalValue += stoneValue[i];
        }

        memset(dp,-1,sizeof(dp));
        int aliceScore = solve(stoneValue,0,1);
        int bobScore = totalValue-aliceScore;

        if(aliceScore == bobScore)return "Tie";
        else if(aliceScore>bobScore)return "Alice";
        return "Bob";
    }
};


//Approach 2 : better
class Solution {
public:
    int n;
    int dp[50001];
    int solve(vector<int>& stones,int i){
        if(i == n)return 0;
        if(dp[i] != -1)return dp[i];

        int res = INT_MIN;

        int value = 0;
        for(int j=i;j<n && j<i+3;j++){
            value += stones[j];
            res = max(res,value-solve(stones,j+1));
        }
        return dp[i] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(dp,-1,sizeof(dp));
        //alicescore-bobscore
        int diff = solve(stoneValue,0);
        cout<<diff;
        if(diff == 0)return "Tie";
        else if(diff>0)return "Alice";
        return "Bob";
    }
};
//problem link: https://leetcode.com/problems/stone-game-ii/description/
// Approach: Dynamic Programming
// Time Complexity: O(N^2)
// Space Complexity: O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[100][100][2];
    int solve(int person,int i,int m,vector<int> &piles){
        if(i>=n)return 0;

        if(dp[i][m][person] != -1)return dp[i][m][person];
        //If Alice turn then take best (result is max)
        //If bob turn then expect for worst(result is min for alice if bob turn)
        int result = (person == 1)?-1:INT_MAX;
        int stones = 0;
        for(int x=1;x<=min(2*m,n-i);x++){
            stones += piles[i+x-1]; //adds continuesly pile by pile

            if(person == 1){//Alice turn
                result = max(result,stones+solve(0,i+x,max(m,x),piles));
            }else{//Bob turn
                result = min(result,solve(1,i+x,max(m,x),piles));
                //Bob scores maximum so alice score will become minimum and
                //Bob stones is not added to alice ones so no need to add stones
            }
        }
        return dp[i][m][person] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        //person == 1(Alice turn)
        //person == 0(Bob turn)
        return solve(1,0,1,piles);
    }
};
//problem link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/

//Time Complexity: O(n * k^2) where k is number of combinations for one column
//Space Complexity: O(n * k) for dp array + O(k) for combinations 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int MOD = 1e9+7;
    int total;
    vector<string> combinations;
    vector<vector<int>> dp;

    void generate(string curr,char prevColor,int i,int m){
        if(i==m){
            combinations.push_back(curr);
            return;
        }

        for(char c : {'R','G','B'}){
            if(prevColor == c)continue;
            generate(curr+c,c,i+1,m);
        }
    }

    int solve(int remaining,int prevIdx,int m){
        if(remaining == 0)return 1;
        if(dp[remaining][prevIdx] != -1)return dp[remaining][prevIdx];
        string prev = combinations[prevIdx];
        int ways = 0;

        for(int i=0;i<total;i++){
            if(i == prevIdx)continue;

            bool flag = true;
            
            string curr = combinations[i];
            for(int j=0;j<m;j++){
                if(prev[j] == curr[j]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ways = (ways+solve(remaining-1,i,m))%MOD;
            }
        }

        return dp[remaining][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        //generate function to generate total possibilites of one column
        generate("",'#',0,m);

        int ways = 0;
        total = combinations.size();

        dp.resize(n,vector<int>(total,-1));

        for(int i=0;i<total;i++){
            ways = (ways+solve(n-1,i,m))%MOD;
        }

        return ways;
    }
};
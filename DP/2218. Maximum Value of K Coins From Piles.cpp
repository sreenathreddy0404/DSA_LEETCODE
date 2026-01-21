//problem link: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
//time complexity: O(n*k)
//space complexity: O(k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[1001][2001];
    int solve(vector<vector<int>>& piles,int i,int k){
        if(k == 0)return 0;
        if(i < 0)return 0;
        if(t[i][k] != -1)return t[i][k];
        int nottake = solve(piles,i-1,k);
        int take = INT_MIN;
        int sum = 0;
        for(int j=0;j<piles[i].size();j++){
            if(k-j-1>=0){
                sum += piles[i][j];
                int money = sum + solve(piles,i-1,k-j-1);
                take = max(take,money);
            }
        }

        return t[i][k] = max(take,nottake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        memset(t,-1,sizeof(t));
        return solve(piles,n-1,k);
    }
};
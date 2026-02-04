//problem link: https://www.leetcode.com/problems/trionic-array-ii

#include <bits/stdc++.h>
using namespace std;

//Memoization solution
//Time Complexity: O(N*4) = O(N)
//Space Complexity: O(N)
class Solution {
public:
    typedef long long ll;
    int n;

    vector<vector<ll>> dp;
    ll solve(vector<int>& nums,int i,int trend){
        if(i == n){
            if(trend == 3)return 0;
            else return LLONG_MIN/2;
        }

        if(dp[i][trend] != -1)return dp[i][trend];

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        if(trend == 0){
            skip = solve(nums,i+1,trend);
        }

        if(trend == 3){
            take = nums[i];
        }

        if(i+1<n){
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && curr < next){
                take = curr + solve(nums,i+1,1);
            }else if(trend == 1){
                if(curr < next){
                    take = curr + solve(nums,i+1,1);
                }else if(curr > next){
                    take = curr + solve(nums,i+1,2);
                }
            }else if(trend == 2){
                if(curr > next){
                    take = curr + solve(nums,i+1,2);
                }else if(curr < next){
                    take = curr + solve(nums,i+1,3);
                }
            }else if(trend == 3 && curr < next){
                take = max(take,curr + solve(nums,i+1,3));
            }
        }

        return dp[i][trend] = max(take,skip);
    }
    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,vector<ll>(4,-1));
        return solve(nums,0,0);
    }
};
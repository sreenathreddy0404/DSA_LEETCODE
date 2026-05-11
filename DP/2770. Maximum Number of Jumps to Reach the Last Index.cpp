// Problem Link : https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
// Time Complexity : O(n^2) where n is the size of the input array
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;
    int helper(vector<int>& nums,int target,int i){
        if(i == n-1)return 0;
        if(dp[i] != -1) return dp[i];
        int res = -1e9;
        for(int j=i+1;j<n;j++){
            int diff = nums[j]-nums[i];
            if(-target <= diff && diff <= target){
                res = max(res,1+helper(nums,target,j));
            }
        }
        return dp[i] = res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp.resize(n,-1);
        int res = helper(nums,target,0);

        if(res < 0)return -1;
        return res;
    }
};
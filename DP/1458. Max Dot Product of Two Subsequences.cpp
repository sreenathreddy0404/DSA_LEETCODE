// Problem Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// Space Complexity: O(n1*n2)
// Time Complexity: O(n1*n2)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n1,n2;
    vector<vector<int>> dp;
    int solve(vector<int>& nums1,vector<int>& nums2,int i,int j){
        if(i == n1 || j == n2){
            return -1e7;
        }
        if(dp[i][j] != -1)return dp[i][j];

        int res = INT_MIN;
        //skip
        res = max(res,solve(nums1,nums2,i+1,j));
        res = max(res,solve(nums1,nums2,i,j+1));

        //take
        int prod = nums1[i]*nums2[j];
        res = max(res, prod+solve(nums1,nums2,i+1,j+1));

        return dp[i][j] = max(prod,res);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();
        dp.resize(n1,vector<int>(n2,-1));
        return solve(nums1,nums2,0,0);
       
    }
};
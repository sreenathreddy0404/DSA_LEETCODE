// problem link : https://leetcode.com/problems/minimum-removals-to-balance-array/description/
// time complexity : O(N)
// space complexity : O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int maxLen = 0;

        while(r<n){
            if(1LL*nums[r]<=1LL*nums[l]*k){
                maxLen = max(maxLen,r-l+1);
                r++;
            }else{
                l++;
            }
        }

        return n-maxLen;
    }
};
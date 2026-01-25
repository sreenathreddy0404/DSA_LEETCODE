// Problem Link : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Time Complexity: O(N log N)
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1)return 0;

        int n = nums.size();

        sort(nums.begin(),nums.end());
        int ans = INT_MAX;

        for(int i=0;i<=n-k;i++){
            int minDiff = nums[i+k-1]-nums[i];
            ans = min(ans,minDiff);
        }

        return ans;
    }
};
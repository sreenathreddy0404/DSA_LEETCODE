// Problem Link : https://leetcode.com/problems/maximum-total-subarray-value-i/
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maximum = INT_MIN;
        int minimum = INT_MAX;

        int n = nums.size();

        for(int i=0;i<n;i++){
            maximum = max(maximum,nums[i]);
            minimum = min(minimum,nums[i]);
        }

        long long value = maximum-minimum;
        return value*k;
    }
};
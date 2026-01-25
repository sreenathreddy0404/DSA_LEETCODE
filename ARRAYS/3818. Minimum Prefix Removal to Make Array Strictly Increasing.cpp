//Problem Link: https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/
//Time Complexity: O(N)
//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int ind = 0;
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1]){
                ind = i+1;
            }
        }

        return ind;
    }
};
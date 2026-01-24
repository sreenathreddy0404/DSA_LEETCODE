//problem link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Time Complexity: O(n)
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int maxPairSum = nums[0]+nums[n-1];

        int left = 1;
        int right = n-2;
        while(left<right){
            int pairSum = nums[left]+nums[right];
            maxPairSum = max(maxPairSum,pairSum);
            left++;
            right--;
        }

        return maxPairSum;
    }
};
// Problem Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(true){
            int minSum = INT_MAX;
            bool flag = true;
            int ind = -1;
            int n = nums.size();
            
            for(int i=0;i<n-1;i++){
                if(nums[i] > nums[i+1])flag = false;
                int sum = nums[i]+nums[i+1];

                if(minSum > sum){
                    ind = i;
                    minSum = sum;
                }
            }

            if(flag)return ans;

            nums[ind] = minSum;
            nums.erase(nums.begin()+(ind+1));
            ans++;
        }

        return ans;
    }
};
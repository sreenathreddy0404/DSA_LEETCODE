// Problem link : https://leetcode.com/problems/contiguous-array/description/
// Time Complexity : O(N)
// Space Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> um;
        um[0] = -1;
        int count0 = 0;
        int count1 = 0;
        int n = nums.size();
        int maxlen = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 0)count0++;
            else count1++;

            int diff = count0-count1;
            if(um.count(diff)){
                maxlen = max(maxlen,i-um[diff]);
            }else{
                um[diff] = i;
            }
        }
        return maxlen;
    }
};
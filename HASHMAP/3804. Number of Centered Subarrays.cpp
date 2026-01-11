//Problem link : https://leetcode.com/problems/number-of-centered-subarrays/
//Time complexity: O(n^2)
//Space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        unordered_set<int> us(nums.begin(),nums.end());

        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            long long sum = 0;
            unordered_set<int> us2;
            for(int j=i;j<n;j++){
                us2.insert(nums[j]);
                sum += nums[j];
                if(us2.find(sum) != us2.end())count++;
            }
        }

        return count;
    }
};
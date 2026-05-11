// Problem Link : https://leetcode.com/problems/separate-the-digits-in-an-array/
// Time Complexity : O(n*log(m)) where n is the size of the input array and m is the length of maximum element in the array
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        for(int i=0;i<n;i++){
            string temp = to_string(nums[i]);

            for(auto ch:temp){
                res.push_back(ch-'0');
            }
        }

        return res;
    }
};
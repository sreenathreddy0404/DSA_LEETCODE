//problem link: https://www.leetcode.com/problems/transformed-array
//time complexity: O(N)
//space complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            ans[i] = nums[(i+nums[i]+100*n)%n];
        }

        return ans;
    }
};
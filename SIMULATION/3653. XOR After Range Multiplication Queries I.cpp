// problem link : https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
// Time Complexity: O(N*M)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            while(l <= r && l < n){
                nums[l] = (1LL*nums[l]*v)%mod;
                l += k;
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans ^= nums[i];
        }

        return ans;
    }
};
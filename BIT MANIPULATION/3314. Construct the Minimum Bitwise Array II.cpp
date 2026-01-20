//problem link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
//time complexity: O(n*32)
//space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n,-1);


        for(int i=0;i<n;i++){
            if(nums[i] == 2) continue;
            int t = nums[i];

            int j;
            for(j=0;j<32;j++){
                if(((t>>(j+1))&1) > 0)continue;
                break;
            }

            t = 1<<j;

            res[i] = (nums[i]^t);
        }
        return res;
    }
};
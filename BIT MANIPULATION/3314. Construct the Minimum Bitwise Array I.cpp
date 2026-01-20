//problem link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/
//time complexity: O(n*m) m is largest number in arr
//space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if((j|(j+1)) == nums[i]){
                    ans[i] = j;
                    break;
                }
            }
        }

        return ans;
    }
};
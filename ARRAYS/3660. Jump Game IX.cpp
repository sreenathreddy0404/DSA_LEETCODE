// Problem Link: https://leetcode.com/problems/jump-game-ix/
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxi(n,0);
        maxi[0] = nums[0];
        for(int i=1;i<n;i++){
            maxi[i] = max(nums[i],maxi[i-1]);
        }

        vector<int> mini(n,0);
        mini[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i] = min(nums[i],mini[i+1]);
        }

        vector<int> ans(n,0);
        ans[n-1] = maxi[n-1];

        for(int i=n-2;i>=0;i--){
            if(maxi[i] > mini[i+1])ans[i] = ans[i+1];
            else ans[i] = maxi[i];
        }

        return ans;
    }
};
//problem link : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/
// Time Complexity: O(N^3)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int len = k-i;
                        if(ans == -1){
                            ans = 2*len;
                        }else{
                            ans = min(ans,2*len);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
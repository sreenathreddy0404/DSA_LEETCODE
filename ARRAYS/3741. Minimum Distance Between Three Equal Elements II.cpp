//problem link : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
// Time Complexity: O(NlogN)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {nums[i],i};
        }

        sort(arr.begin(),arr.end());
        int ans = -1;

        for(int i=0;i<n-2;i++){
            if(arr[i].first == arr[i+2].first){
                int len = arr[i+2].second - arr[i].second;
                if(ans == -1)ans = 2*len;
                else ans = min(ans,2*len);
            }
        }

        return ans;
    }
};
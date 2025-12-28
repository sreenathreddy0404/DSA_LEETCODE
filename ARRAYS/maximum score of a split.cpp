//problem link: https://leetcode.com/problems/minimum-score-of-a-split-array/description/
// Time Complexity: O(N) where N is number of elements in the array
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n,0);

        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        vector<int> suffixMin(n,0);
        int mini = nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            suffixMin[i] = mini;
            mini = min(mini,nums[i]);
        }

        long long maxScore = INT_MIN;
        for(int i=0;i<n-1;i++){
            maxScore = max(maxScore,prefixSum[i]-suffixMin[i]);
        }

        return maxScore;
    }
};
// problem link : https://leetcode.com/problems/count-dominant-indices/description/
// time Complexity : O(N)
// space complexity : O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);

        prefix[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            prefix[i] = prefix[i+1]+nums[i];
        }

        int count = 0;
        for(int i=0;i<n-1;i++){
            int n1 = n-i-1;
            int sum = prefix[i+1];
            float avg = sum/float(n1);
            if(nums[i] > avg)count++;
        }
        return count;
    }
};
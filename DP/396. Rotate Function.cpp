// Problem link : https://leetcode.com/problems/rotate-function/
// Time Complexity : O(n)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // f(i+1) = f(i)+sum-n*nums[(n-i)%n];
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int prevSum = 0;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            prevSum += nums[i]*i;
        }

        int maxSum = prevSum;
        for(int i=1;i<n;i++){
            int currSum = prevSum + sum -n*nums[(n-i)%n];
            prevSum = currSum;
            maxSum = max(maxSum,prevSum);
        }

        return maxSum;

    }
};
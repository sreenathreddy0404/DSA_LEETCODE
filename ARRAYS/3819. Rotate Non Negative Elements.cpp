//Problem Link: https://leetcode.com/problems/Rotate-Non-Negative-Elements/
//Time Complexity: O(N)
//Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNegInd;
        int n1 = nums.size();

        for(int i=0;i<n1;i++){
            if(nums[i] >= 0){
                nonNegInd.push_back(nums[i]);
            }
        }

        int n2 = nonNegInd.size();
        if(n2 != 0)k = k%n2;
        else return nums;

        reverse(nonNegInd.begin(),nonNegInd.begin()+k);
        reverse(nonNegInd.begin()+k,nonNegInd.end());
        reverse(nonNegInd.begin(),nonNegInd.end());

        int j=0;
        for(int i=0;i<n1;i++){
             if(nums[i]>=0){
                 nums[i] = nonNegInd[j];
                 j++;
             }
        }

        return nums;
    }
};
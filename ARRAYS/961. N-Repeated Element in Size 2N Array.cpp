//problem link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Time Complexity : O(N) where N is the size of the array
// Space Complexity : O(1)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> hashset;

        for(auto n:nums){
            if(hashset.find(n) != hashset.end())return n;
            hashset.insert(n);
        }

        return -1;
    }
};
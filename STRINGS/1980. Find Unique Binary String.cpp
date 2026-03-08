// problem link : https://leetcode.com/problems/find-unique-binary-string/description
// Time Complexity : O(N)
// Space Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";
        for(int i=0;i<n;i++){
            char bit = nums[i][i];

            if(bit == '0')res+='1';
            else res+='0';
        }

        return res;
    }
};
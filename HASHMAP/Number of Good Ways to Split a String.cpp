// Problem Link: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
// Time Complexity: O(N) where N is the length of the string
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> right;
        unordered_map<char,int> left;
        for(auto &ch:s){
            right[ch]++;
        }

        int n = s.size();
        int count = 0;
        for(int i=0;i<n-1;i++){
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]] == 0)right.erase(s[i]);

            int l = left.size();
            int r = right.size();
            if(l==r)count++;
            if(l>r)break;
        }
        return count;
    }
};
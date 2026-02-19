// problem link : https://leetcode.com/problems/count-binary-substrings/description/
// time complexity : O(N)
// space complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();

        int count = 0;
        int r = 0;
        int prev = 0;
        while(r<n){
            int l = r++;
            while(r<n && s[r] == s[l])r++;
            int len = r-l;
            count += min(prev,len);
            prev = len;
        }

        return count;
    }
};
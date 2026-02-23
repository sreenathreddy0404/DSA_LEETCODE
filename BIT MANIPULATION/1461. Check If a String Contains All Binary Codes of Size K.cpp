// Problem Link : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/
// Time Complexity : O(n*k) where n is the length of the string s and k is the size of binary codes
// Space Complexity : O(2^k) where k is the size of the binary codes

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> us;
        int n = s.size();
        for(int i=0;i<=n-k;i++){
            us.insert(s.substr(i,k));
        }
        return us.size() == pow(2,k);
    }
};
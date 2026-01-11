// problem link: https://leetcode.com/problems/count-residue-prefixes/description/
// time complexity: O(n)
// space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        int count = 0;
        unordered_map<char,int> um;
        for(int i=0;i<n;i++){
            um[s[i]]++;
            if(um.size() == (i+1)%3)count++;
        }
        return count;
    }
};
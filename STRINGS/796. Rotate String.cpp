// Problem Link : https://leetcode.com/problems/rotate-string/
// Time Complexity : O(n)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        s = s + s;
        if(s.find(goal) != string::npos)return true;
        return false;
    }
};
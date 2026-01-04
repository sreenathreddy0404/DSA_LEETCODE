//problem link: https://leetcode.com/problems/largest-even-number/
//Time Complexity: O(n) where n is length of string s
//Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestEven(string s) {
        int j = s.size()-1;
        while(j>=0 && s[j] == '1')j--;
        return s.substr(0,j+1);
    }
};
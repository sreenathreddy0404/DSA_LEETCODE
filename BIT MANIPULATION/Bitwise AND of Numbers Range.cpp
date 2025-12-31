//problem link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
// Time Complexity: O(log n) where n is the upper limit of the range
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right){
            count++;
            left>>=1;
            right>>=1;
        }
        return (left<<count);
    }
};
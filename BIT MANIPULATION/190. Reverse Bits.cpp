// Problem Link : https://leetcode.com/problems/reverse-bits/description
// Time Complexity : O(32)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int num = 0;
        for(int i=31;i>0;i--){
            int a = (n & 1);
            num = num | (a<<i);
            n >>= 1;
        }

        return num;
    }
};
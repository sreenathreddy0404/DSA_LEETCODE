// Problem linK : https://leetcode.com/problems/binary-number-with-alternating-bits/description
// Time Complexity : O(32)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = n&1;

        while(n > 0){
            if(flag != (n&1))break;

            flag = !flag;
            n >>= 1;
        }

        return n == 0;
    }
};
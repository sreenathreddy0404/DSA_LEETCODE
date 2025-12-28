//problem link: https://leetcode.com/problems/smallest-integer-divisible-by-k/description/
// Time Complexity: O(K)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2 == 0 || k %5 == 0)return -1;

        int len = 1;
        int num = 1;
        while(len <= k){
            num = num % k;
            if(num == 0)return len;
            num = num*10+1;
            len++;
        }
        return -1;
    }
};
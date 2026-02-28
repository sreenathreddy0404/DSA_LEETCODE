//Problem link : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description
// Time complexity : O(N)
// Space complexity : O(1)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long long ans = 0;
        int bitlen = 0; //stores no bits in i
        for(int i=1;i<=n;i++){
            //condition for checking if i is power of 2 or not
            //if i is power of 2 then (i&(i-1)) == 0
            if((i & (i-1)) == 0){
                //if i is power of two then lenght of its bits increased by 1
                bitlen++;
            }

            ans = (ans<<bitlen | i)%mod;
        }

        return ans;
    }
};
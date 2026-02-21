// Problem Link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
// Time Complexity : O(N*b)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> primes(33,true);
        primes[1] = false;
        for(int i=2;i<32;i++){
            if(!primes[i])continue;
            int j = 2;
            while(i*j <= 32){
                primes[i*j] = false;
                j++;
            }
        }

        int count = 0;
        for(int i=left;i<=right;i++){
            if(primes[__builtin_popcount(i)])count++;
        }

        return count;
    }
};
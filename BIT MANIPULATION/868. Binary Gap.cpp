// Problem Link : https://leetcode.com/problems/binary-gap/description
// Time Complexity : O(b) where b is the number of bits in the binary representation of n
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0;
        int count = 0;
        bool firstOne = true;
        while(n > 0){
            if(n&1){
                if(!firstOne){
                    maxDist = max(maxDist,count+1);
                }else{
                    firstOne = false;
                }
                count = 0;
            }else{
                count++;
            }
            n>>=1;
        }
        return maxDist;
    }
};
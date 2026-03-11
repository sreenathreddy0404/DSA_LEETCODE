//problem link : https://leetcode.com/problems/complement-of-base-10-integer/description
// Time Complexity : O(1) since we are dealing with 32 bits
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)return 1;
        string num = bitset<32> (n).to_string();
        int i=0;
        while(i<32 && num[i] == '0')i++;
        while(i<32 && num[i] == '1')i++;

        int ans = 0;
        for(int j=i;j<32;j++){
            ans = ans*2 +(1-(num[j]-'0'));
        }
        return ans;
    }
};
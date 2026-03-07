// problem link : https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description
// Time Complexity : O(N)
// Space Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string str = s+s;
        int left = 0;
        int minflips = INT_MAX;

        //flips required to store 1 in even and 0 in odd index
        int flips1 = 0;
        //flips required to store 0 in even and 1 in odd index
        int flips2 = 0;
        for(int right=0;right<2*n;right++){
            if(right%2 == 0){
                if(str[right] == '0')flips1++;
                else flips2++;
            }else{
                if(str[right] == '1')flips1++;
                else flips2++;
            }

            if(right-left+1 > n){
                if(left%2 == 0){
                    if(str[right] == '0')flips1--;
                    else flips2--;
                }else{
                    if(str[right] == '1')flips1--;
                    else flips2--;
                }
                left++;
            }

            if(right-left+1 == n){
                minflips = min({minflips,flips1,flips2});
            }
        }

        return minflips;
    }
};
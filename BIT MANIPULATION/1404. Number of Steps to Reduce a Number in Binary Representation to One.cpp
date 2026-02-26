// Problem Link : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description
// Time Complexity : O(n) where n is the length of the binary string
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        int count = 0;
        int carry = 0;

        for(int i=0;i<n;i++){
            if(i == n-1){
                if(carry == 1)count++;
                break;
            }

            if(s[i] == '1'){
                if(carry == 1)count++;
                else{
                    count+=2;
                    carry = 1;
                }
            }else{
                if(carry == 1){
                    count+=2;
                }else{
                    count++;
                }
            }
        }

        return count;
    }
};
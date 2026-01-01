//problem link: https://leetcode.com/problems/plus-one/
//Time Complexity: O(n)
//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i] != 9){
                digits[i]++;
                break;
            }else{
                digits[i] = 0;
            }
        }

        if(digits[0] == 0){
            digits.resize(n+1,0);
            digits[0] = 1;
        }
        
        return digits;
    }
};
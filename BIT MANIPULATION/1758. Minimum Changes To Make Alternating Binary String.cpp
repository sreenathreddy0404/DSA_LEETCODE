// Problem Link : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description
// Time Complexity : O(N)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int count1 = 0;
        int count2 = 0;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(i%2 == 0){
                if(s[i] == '1'){
                    count1++;
                }else{
                    count2++;
                }
            }else{
                if(s[i] == '1'){
                    count2++;
                }else{
                    count1++;
                }
            }
        }

        return min(count1,count2);
    }
};
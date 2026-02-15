// Problem Link : https://leetcode.com/problems/add-binary/description
// Time Complexity : O(N)
// Space Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;

        int n = a.size();
        int m = b.size();

        int i = n-1;
        int j = m-1;

        string ans = "";
        while(i>=0 && j>=0){
            int b1 = a[i];
            int b2 = b[j];

            if(b1 == '0' && b2 == '0'){
                if(carry == 1){
                    ans.push_back('1');
                    carry = 0;
                }
                else{
                    ans.push_back('0');
                } 
            }else if((b1 == '1' && b2 == '0') || b1 == '0' && b2 == '1'){
                if(carry == 1){
                    ans.push_back('0');
                }else{
                    ans.push_back('1');
                }
            }else{
                if(carry == 1){
                    ans.push_back('1');
                }else{
                    ans.push_back('0');
                }
                carry = 1;
            }
            i--;
            j--;
        }

        while(i>=0){
            if(a[i] == '0'){
                if(carry == 1){
                    ans.push_back('1');
                    carry = 0;
                }else{
                    ans.push_back('0');
                }
            }else{
                if(carry == 1){
                    ans.push_back('0');
                }else{
                    ans.push_back('1');
                }
            }
            i--;
        }
        while(j>=0){
            if(b[j] == '0'){
                if(carry == 1){
                    ans.push_back('1');
                    carry = 0;
                }else{
                    ans.push_back('0');
                }
            }else{
                if(carry == 1){
                    ans.push_back('0');
                }else{
                    ans.push_back('1');
                }
            }
            j--;
        }

        if(carry == 1)ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//problem link: https://leetcode.com/problems/palindrome-number/
// Time Complexity : O(log10(n)) where n is the input number
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            int a = x;
            long reverse = 0;
            while(a!=0){
                int b = a%10;
                reverse = reverse*10+b;
                a = a/10;
            }
            if(x == reverse){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
//problem link: https://leetcode.com/problems/valid-palindrome/
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto ch:s){
            if(isalnum(ch)){
                str += tolower(ch);
            }
        }

        string rev = str;
        reverse(str.begin(),str.end());

        return rev == str;
    }
};

// Another Approach: Two Pointer Technique
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else if(tolower(s[i++]) != tolower(s[j--]))return false;
        }
        return true;
    }
};
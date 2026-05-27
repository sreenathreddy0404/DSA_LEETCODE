// Problem Link : https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/
// Time Complexity : O(n)
// Space Complexity : O(3*26)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int countSpecials = 0;
        vector<int> uppercase(26,0);
        vector<int> lowercase(26,0);
        vector<bool> specialChars(26,false);

        for(auto ch:word){
            if('a' <= ch && ch <= 'z'){
                lowercase[ch-'a']++;
                if(lowercase[ch-'a'] >= 1 && uppercase[ch-'a'] >=1){
                    specialChars[ch-'a'] = false;
                    lowercase[ch-'a'] = INT_MIN;
                }
            }else{
                uppercase[ch-'A']++;
                if(lowercase[ch-'A'] >= 1 && uppercase[ch-'A']==1){
                    specialChars[ch-'A'] = true;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(specialChars[i])countSpecials++;
        }

        return countSpecials;
    }
};
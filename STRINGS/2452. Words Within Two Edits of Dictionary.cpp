// Problem Link : https://leetcode.com/problems/words-within-two-edits-of-dictionary/
// Time Complexity : O(n*m*k)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canEdit(string &s1, string &s2){
        int n = s1.size();

        int count = 0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                count++;
                if(count > 2)return false;
            }
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries.size();
        int m = dictionary.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(canEdit(queries[i],dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
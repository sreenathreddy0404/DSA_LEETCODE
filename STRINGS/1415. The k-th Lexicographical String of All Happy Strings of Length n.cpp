// Problem link : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/
// Time complexity : O(2^n) where n is the length of the happy strings
// Space Complexity : O(n) where n is the length of the happy strings

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ans = "";
    int count = 0;
    void solve(int n,int k,string s){
        if(count == k)return;
        if(s.size() == n){
            count++;
            if(count == k){
                ans = s;
            }
            return;
        }

        for(char ch = 'a';ch <= 'c';ch++){
            if(s != "" && s.back() == ch)continue;
            s.push_back(ch);
            solve(n,k,s);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        solve(n,k,"");
        return ans;
    }
};
//problem link: https://leetcode.com/problems/pyramid-transition-matrix/
// Time Complexity: O(M^N) where N is length of bottom and M is number of allowed transitions
// Space Complexity: O(M^N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,vector<char>> um;
    unordered_map<string,bool> dp;
    vector<string> getNext(string& s){
        int n = s.size();
        vector<string> ans(1,"");

        for(int i=0;i<n-1;i++){
            string t = "";
            t+=s[i];
            t+=s[i+1];
            if(um.count(t) == 0)return {};

            vector<string> temp;
            for(auto ch:um[t]){
                for(int i=0;i<ans.size();i++){
                    string a = ans[i];
                    a+=ch;
                    temp.push_back(a);
                }
            }
            ans = temp;
        }

        return ans;
    }
    bool solve(string &bottom){
        if(bottom.size() == 2){
            if(um.find(bottom) != um.end())return true;
            return false;
        }

        if(dp.find(bottom) != dp.end())return dp[bottom];

        vector<string> possibleNext = getNext(bottom);
        // cout<<bottom<<"->";
        // for(auto &s:possibleNext){
        //     cout<<s<<",";
        // }
        // cout<<endl;
        for(auto &s:possibleNext){
            if(solve(s))return dp[bottom] = true;
        }

        return dp[bottom]=false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        um.clear();
        dp.clear();
        for(auto &s:allowed){
            string b = "";
            b+=s[0];
            b+=s[1];
            um[b].push_back(s[2]);
        }

        return solve(bottom);
    }
};
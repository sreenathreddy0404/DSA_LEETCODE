//problem link: https://leetcode.com/problems/pyramid-transition-matrix/
// Time Complexity: O(M^N) where N is length of bottom and M is number of allowed transitions
// Space Complexity: O(M^N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,vector<char>> um;
    unordered_map<string,bool> dp;
    bool backtrack(string &curr,int i,string above){
        if(curr.size() == 1)return true;
        if(i == curr.size()-1){
            if(dp.find(above) != dp.end())return dp[above];
            return dp[above] = backtrack(above,0,"");
        }

        string str = curr.substr(i,2);
        if(um.find(str) == um.end())return false;

        for(auto &ch:um[str]){
            above.push_back(ch);
            if(backtrack(curr,i+1,above))return true;
            above.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        um.clear();
        dp.clear();
        for(auto &s:allowed){
            string b = s.substr(0,2);
            um[b].push_back(s[2]);
        }

        return backtrack(bottom,0,"");
    }
};
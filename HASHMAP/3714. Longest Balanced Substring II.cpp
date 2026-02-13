// problem link : https://leetcode.com/problems/longest-balanced-substring-ii/description/
// Time complexity : o(N)
// Space complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalancedTwoLengthSubstring(string &s,char x,char y){
        int n = s.size();

        unordered_map<int,int> mp;
        mp[0] = -1;

        int countX = 0;
        int countY = 0;
        int maxlen = 0;

        for(int i=0;i<n;i++){
            if(s[i] == x)countX++;
            else if(s[i] == y)countY++;
            else {
                countX = 0;
                countY = 0;
                mp.clear();
                mp[0] = i;
                continue;
            }
            int diff = countX-countY;
            if(mp.count(diff)){
                maxlen = max(maxlen,i-mp[diff]);
            }else{
                mp[diff] = i;
            }
        }

        return maxlen;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxlen = 0;
        //longest single character balanced substring
        //simple sliding window technique to find maxled
        int l = 0;
        int r = 0;
        while(r<n){
            if(s[r] == s[l]){
                r++;
            }else{
                maxlen = max(maxlen,r-l);
                l = r;
                r++;
            }
        }
        maxlen = max(maxlen,r-l);

        //longest two charcters balanced substring
        maxlen = max(maxlen,longestBalancedTwoLengthSubstring(s,'a','b'));
        maxlen = max(maxlen,longestBalancedTwoLengthSubstring(s,'b','c'));
        maxlen = max(maxlen,longestBalancedTwoLengthSubstring(s,'c','a'));

        //longest three charcters balanced substring
        unordered_map<string,int> hashmap;
        hashmap["0#0"] = -1;
        int countA = 0;
        int countB = 0;
        int countC = 0;

        for(int i=0;i<n;i++){
            if(s[i] == 'a')countA++;
            else if(s[i] == 'b')countB++;
            else countC++;

            int diff1 = countB - countA;
            int diff2 = countC - countB;

            string key = to_string(diff1) +  "#" + to_string(diff2);

            if(hashmap.count(key)){
                int j = hashmap[key];
                maxlen = max(maxlen,i-j);
            }else{
                hashmap[key] = i;
            }
        }

        return maxlen;
    }
};
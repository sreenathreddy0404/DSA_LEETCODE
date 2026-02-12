// Problem link : https://leetcode.com/problems/longest-balanced-substring-i/description
// Time Complexity : O(N^2)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxL = 0;
        for(int i=0;i<n;i++){
            vector<int> hashmap(26,0);
            for(int j=i;j<n;j++){
                hashmap[s[j]-'a']++;

                int freq = hashmap[s[j]-'a'];
                for(int k=0;k<26;k++){
                    if(hashmap[k] != 0 && hashmap[k] != freq){
                        break;
                    }

                    if(k == 25){
                        maxL = max(maxL,j-i+1);
                    }
                }
            }
        }

        return maxL;
    }
};
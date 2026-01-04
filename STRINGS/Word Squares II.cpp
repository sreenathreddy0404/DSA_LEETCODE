//problem link: https://leetcode.com/problems/word-squares-ii/
//time Complexity: O(n^4) where n is number of words
//space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        unordered_map<char,vector<string>> byFirst;

        for(auto &word:words){
            byFirst[word[0]].push_back(word);
        }

        vector<vector<string>> res;
        for(auto &top:words){
            for(auto & left:byFirst[top[0]]){
                if(left == top)continue;

                for(auto &right:byFirst[top[3]]){
                    if(right == left || right == top)continue;

                    for(auto &bottom: byFirst[left[3]]){
                        if(bottom == top || bottom == left || bottom == right)continue;

                        if(bottom[3] == right[3]){
                            res.push_back({top,left,right,bottom});
                        }
                    }
                }
            }
        }

        sort(res.begin(),res.end());

        return res;
    }
};
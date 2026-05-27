// Problem Link : https://leetcode.com/problems/word-break/description/
// Time Complexity : O(n*m) where n is the length of the string and m is the average length of the words in the dictionary
// Space Complexity : O(n) for the dp array and O(m*k) for the trie where k is the number of words in the dictionary

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode{
        TrieNode* next[26];
        bool isEnd;
        TrieNode(){
            for(int i=0;i<26;i++){
                next[i] = nullptr;
            }
            isEnd = false;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string &word){
        int n = word.size();
        TrieNode* node = root;
        for(int i=0;i<n;i++){
            int idx = word[i]-'a';
            if(node->next[idx] == nullptr)node->next[idx] = new TrieNode();
            node = node->next[idx];
        }
        node->isEnd = true;
    }

    int n;
    vector<int> dp;
    bool solve(int i,string &s){
        if(i == n)return true;
        if(dp[i] != -1)return dp[i];
        TrieNode* node = root;
        for(int j=i;j<n;j++){
            int idx = s[j]-'a';
            if(node->next[idx] == nullptr)break;
            if(node->next[idx]->isEnd){
                if(solve(j+1,s))return dp[i] = true;
            }
            node = node->next[idx];
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp.resize(n,-1);
        for(auto &word:wordDict) insert(word);

        return solve(0,s);
    }
};
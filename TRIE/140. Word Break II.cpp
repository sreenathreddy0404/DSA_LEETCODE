// Problem Link : https://leetcode.com/problems/word-break-ii/description/
// Time Complexity : O(n*m^2) where n is the length of the string and m is the average length of the words in the dictionary
// Space Complexity : O(n) for the recursion stack and O(m*k) for the trie where k is the number of words in the dictionary

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TreeNode{
        TreeNode* next[26];
        bool isEnd;
        TreeNode(){
            for(int i=0;i<26;i++)next[i] = nullptr;
            isEnd = false;
        }
    };

    TreeNode* root = new TreeNode();

    void insert(string &word){
        int n = word.size();
        TreeNode* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node->next[idx] == nullptr)node->next[idx] = new TreeNode();
            node = node->next[idx];
        }
        node->isEnd = true;
    }

    int n;
    vector<string> ans;
    void solve(int i,string &s,string sentence){
        if(i == n){
            ans.push_back(sentence);
            return;
        }

        string temp = "";
        TreeNode* node = root;
        for(int j=i;j<n;j++){
            int idx = s[j]-'a';
            temp += s[j];
            if(node->next[idx] == nullptr)break;
            if(node->next[idx]->isEnd){
                string temp2 = temp;
                if(sentence.size() > 0)temp2 = sentence + " "+temp;
                solve(j+1,s,temp2);
            }
            node = node->next[idx];
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto &word:wordDict){
            insert(word);
        }
        solve(0,s,"");
        return ans;
    }
};
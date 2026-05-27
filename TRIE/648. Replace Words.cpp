// Problem Link : https://leetcode.com/problems/replace-words/description/
// Time Complexity : O(n*m) where n is the number of words in the sentence and m is the average length of the words in the dictionary
// Space Complexity : O(m*k) for the trie where m is the average length of the words in the dictionary and k is the number of words in the dictionary

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode{
        TrieNode* next[26];
        bool isEnd;

        TrieNode(){
            for(int i=0;i<26;i++)next[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root = new TrieNode();
    
    void insert(string& word){
        TrieNode* node = root;
        
        for(auto ch : word){
            int idx = ch - 'a';

            if(node->next[idx] == nullptr)node->next[idx] = new TrieNode();

            node = node->next[idx];
        }
        node->isEnd = true;
    }

    string getRootWord(string& word){
        TrieNode* node = root;
        string prefix = "";

        for(auto ch:word){
            prefix += ch;
            int idx = ch-'a';

            if(node->next[idx] == nullptr)return word;
            if(node->next[idx]->isEnd)return prefix;

            node = node->next[idx];
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto &word : dictionary)insert(word);

        stringstream ss(sentence);
        string word;
        string result = "";

        while(ss>>word){
            if(!result.empty())result += " ";
            result += getRootWord(word);
        }

        return result;
    }
};
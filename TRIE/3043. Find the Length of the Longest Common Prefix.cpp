//problem link : https://www.leetcode.com/problems/longest-common-prefix/
//time complexity : O(n+m)
//space complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Trie{
        public:
        struct Node{
            Node* next[10] = {nullptr};
        };

        Trie(){
            root = new Node();
        }

        void insert(string num){
            Node* temp = root;

            for(auto c:num){
                if(temp->next[c-'0'] == nullptr)temp->next[c-'0'] = new Node();

                temp = temp->next[c-'0'];
            }
        }

        int getLength(string num){
            Node* temp = root;
            int len = 0;

            for(auto c:num){
                if(temp->next[c-'0'] == nullptr)return len;

                temp = temp->next[c-'0'];
                len++;
            }
            return len;
        }  
        private:
        Node* root;      
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for(int num : arr1){
            trie.insert(to_string(num));
        }
        
        int longest = 0;
        for(int num : arr2){
            int len = trie.getLength(to_string(num));
            longest = max(longest,len);
        }

        return longest;
    }
};
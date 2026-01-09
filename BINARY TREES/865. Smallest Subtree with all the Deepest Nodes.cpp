//problem link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
//time complexity: O(n)
//space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);

        parent[root] = NULL;
        vector<TreeNode*> deepestNodes;
        while(!q.empty()){
            int size = q.size();
            deepestNodes.clear();

            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                deepestNodes.push_back(temp);
                if(temp->left){
                    parent[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    parent[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }

        unordered_set<TreeNode*> lca(deepestNodes.begin(),deepestNodes.end());

        while(lca.size()>1){
            unordered_set<TreeNode*> temp;

            for(auto it:lca){
                temp.insert(parent[it]);
            }
            lca = temp;
        }

        return *lca.begin();
    }
};
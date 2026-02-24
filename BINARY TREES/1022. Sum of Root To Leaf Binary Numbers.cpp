// Problem Link : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
// Time Complexity : O(n) where n is the number of nodes in the binary tree
// Space Complexity : O(h) where h is the height of the binary tree

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
    int bfs(TreeNode* root, int n){
        if(root == NULL)return 0;
        n = ((n<<1) | root->val);

        if(root->left == NULL && root->right == NULL){
            return n;
        }

        return bfs(root->left,n) + bfs(root->right,n);
    }
    int sumRootToLeaf(TreeNode* root) {
        return bfs(root,0);
    }
};
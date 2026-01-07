//problem link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
//time complexity: O(n)
//space complexity: O(h) where h is the height of the tree

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
    int mod = 1e9+7;
    void dfs(TreeNode* root,int &sum){
        if(root == NULL)return;
        sum = sum+root->val;
        dfs(root->left,sum);
        dfs(root->right,sum);
    }

    int dfs2(TreeNode* root,int sum,long long &ans){
        if(root == NULL)return 0;
        int left = dfs2(root->left,sum,ans);
        int right = dfs2(root->right,sum,ans);

        int currSum = (1LL*left+right+root->val)%mod;

        int remSum = (sum-currSum)%mod;

        long long prod = 1LL*currSum*remSum;

        if(prod > ans){
            ans = prod;
        }

        return currSum;
    }
    int maxProduct(TreeNode* root) {
        int sum = 0;
        dfs(root,sum);

        long long ans = 0;
        dfs2(root,sum,ans);
        return ans%mod;
    }
};
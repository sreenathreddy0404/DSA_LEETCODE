//problem link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
//time complexity: O(n)
//space complexity: O(w) where w is the maximum width of the tree

#include<bits/stdc++.h>
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
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int level = 1;
        queue<TreeNode *> q;
        q.push(root);
        long long maxSum = root->val;

        while(!q.empty()){
            int s = q.size();
            long long sum = 0;
            while(s--){
                auto temp = q.front();q.pop();

                sum = sum + temp->val;

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }

            if(sum > maxSum){
                ans = level;
                maxSum = sum;
            }
            level++;
        }
        return ans;
    }
};
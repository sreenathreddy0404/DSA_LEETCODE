// problem link : https://leetcode.com/problems/balance-a-binary-search-tree/description
// time complexity : O(N)
// space complexity : O(N)

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

//Approach 1: using inorder array
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &arr){
        if(root == NULL)return;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    TreeNode* build(TreeNode* root,vector<int>& arr,int low,int high){
        if(low>high)return NULL;

        int mid = low+(high-low)/2;

        TreeNode* newnode = new TreeNode(arr[mid]);
        newnode->left = build(root,arr,low,mid-1);
        newnode->right = build(root,arr,mid+1,high);

        return newnode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        int n = arr.size();
        return build(root,arr,0,n-1);
    }
};
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(NULL), right(NULL){
        
    }
};

//using two stacks
void preorder(TreeNode* root){
    if(root == NULL)return;

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    while(!st1.empty()){
        auto node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left)st1.push(node->left);
        if(node->right)st1.push(node->right);
    }

    while(st2.empty()){
        cout<<st2.top()->val<<" ";
        st2.pop();
    }
    return;
}
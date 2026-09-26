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
void preorder(TreeNode* root){
    if(root == NULL)return;

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        cout<<root->val<<" ";
        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left != NULL)st.push(root->left);
    }
    return;
}
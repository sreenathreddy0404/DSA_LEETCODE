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
void inorder(TreeNode* root){
    if(root == NULL)return;

    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty())break;
            node = st.top();
            st.pop();
            cout<<node->val<<" ";
            node = node->right;
        }
    }
    return;
}
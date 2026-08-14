#include<bits/stdc++.h>
using namespace std;

int lca(vector<int> &tree, int node, int a,int b){
    if(node >= tree.size())return -1;
    if(tree[node] == -1)return -1;
    if(tree[node] == a || tree[node] == b){
        return tree[node];
    }

    int left = lca(tree,2*node+1,a,b);
    int right = lca(tree,2*node+2,a,b);
    if(left != -1 && right != -1)return tree[node];
    if(left != -1) return left;
    return right;
}

int main(){
    vector<int> tree = {10,20,30,40,50,60,70,80,90,-1,-1,-1,-1,-1,-1};
    int a = 70;
    int b = 60;
    cout<<lca(tree,0,a,b);
}
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

void dfs2(vector<vector<PII>>& adj,int u,int parent,vector<int>& ans){
    for(auto &it:adj[u]){
        int v = it.first;
        if(v == parent)continue;
        int cost = it.second;
        if(cost == 0) ans[v] = ans[u] + 1;
        else ans[v] = ans[u] - 1;
        dfs2(adj,v,u,ans);
    }
}

void dfs(vector<vector<PII>>& adj,int u,int parent,vector<int>& ans){
    for(auto &it:adj[u]){
        int v = it.first;
        if(v == parent)continue;
        int cost = it.second;
        ans[0] += cost;
        dfs(adj,v,u,ans);
    }
}

vector<int> minReorder(int nodes,vector<int>& from,vector<int>& to){
    int edges = nodes-1;

    vector<vector<PII>> adj(nodes);
    for(int i=0;i<edges;i++){
        int u = from[i];
        int v = to[i];
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }

    vector<int> ans(nodes,0);
    dfs(adj, 0, -1, ans);
    dfs2(adj,0,-1,ans);

    return ans;
}

int main(){
    int nodes = 4;
    vector<int> from = {0,0,2};
    vector<int> to = {2,1,3};

    vector<int> result = minReorder(nodes,from,to);
    for(int i=0;i<nodes;i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}
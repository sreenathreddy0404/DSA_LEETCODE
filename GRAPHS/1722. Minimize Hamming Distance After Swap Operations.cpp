// problem link : https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& adj, int u,vector<int>& indexes,vector<bool>& visited){
        visited[u] = true;
        indexes.push_back(u);
        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(adj,v,indexes,visited);
            }
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> adj(n);
        for(auto &edge:allowedSwaps){
            int v = edge[0];
            int u = edge[1];

            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        int ans = 0;

        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int> indexes;
                dfs(adj,i,indexes,visited);
                multiset<int> ms;
                for(int j=0;j<indexes.size();j++){
                    ms.insert(source[indexes[j]]);
                }

                for(int j=0;j<indexes.size();j++){
                    auto it = ms.find(target[indexes[j]]);
                    if(it != ms.end()){
                        ms.erase(it);
                    }
                }

                ans+=ms.size();
            }
        }

        return ans;
    }
};
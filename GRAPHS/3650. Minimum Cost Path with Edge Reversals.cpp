//problem link: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/
//Time Complexity: O((V + E) log V)
//Space Complexity: O(V + E)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int,int> PII;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> adj(n);

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        vector<int> dist(n,1e8);

        priority_queue<PII,vector<PII>,greater<PII>> pq;

        //{dist,node}
        pq.push({0,0});
        dist[0] = 0;

        while(!pq.empty()){
            PII temp = pq.top();
            pq.pop();
            int d = temp.first;
            int u = temp.second;
            if(d > dist[u])continue;

            for(auto &it:adj[u]){
                int v = it.first;
                int w = it.second;
                if(d+w < dist[v]){
                    dist[v] = d+w;
                    pq.push({dist[v],v});
                }
            }
        }

        if(dist[n-1] == 1e8)return -1;
        return dist[n-1];
    }
};
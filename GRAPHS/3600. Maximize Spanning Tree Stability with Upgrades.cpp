// problem link : https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/description
// Time Complexity : O(E log E) where E is the number of edges
// Space Complexity : O(E) where E is the number of edges

#include <bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n,0);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] == u)return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)return false;
        if(rank[pv] == rank[pu]){
            parent[pu] = pv;
            rank[pv]++;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
        }

        return true;
    }
};
class Solution {
public:
    bool check(vector<vector<int>>& edges,int n, int k,int x){
        int used = 0;
        int upgrades = 0;
        DSU dsu(n);

        vector<vector<int>> optional;

        int m = edges.size();
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int s = edges[i][2];
            int must = edges[i][3];

            if(must){
                //if must edge is less than our current strength we return false.
                if(s < x)return false;
                if(!dsu.unite(u,v))return false;

                used++;
                
            }else{
                optional.push_back({u,v,s});
            }
        }

        m = optional.size();
        for(int i=0;i<m;i++){
            int u = optional[i][0];
            int v = optional[i][1];
            int s = optional[i][2];
            if(s >= x){
                if(dsu.unite(u,v)){
                    used++;
                }
            }
        }

        for(int i=0;i<m;i++){
            int u = optional[i][0];
            int v = optional[i][1];
            int s = optional[i][2];
            if(s < x && 2*s >= x){
                if(dsu.unite(u,v)){
                    used++;
                    upgrades++;
                }
            }
        }

        return used == n-1 && upgrades <= k;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low = 0;
        int high = 2e5;
        int ans = -1;

        while(low <= high){
            int mid = low+(high-low)/2;

            if(check(edges,n,k,mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return ans;
    }
};
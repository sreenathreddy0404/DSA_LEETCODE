//problem link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/
//time complexity: O(26 * (E + V) + N) where E is number of edges in graph, V is number of vertices in graph and N is length of source string
//space complexity: O(26 * 26 + V) for hashmap and adjacency list
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int, int> PII;
    typedef pair<long long,int> PLI;
    long long hashmap[26][26];

    void solve(vector<vector<PII>>& adj, int i){
        vector<long long> dist(26,LLONG_MAX);
        priority_queue<PLI,vector<PLI>,greater<PLI>> pq;
        pq.push({0,i});
        dist[i] = 0;

        while(!pq.empty()){
            auto &temp = pq.top();
            long long d = temp.first;
            int u = temp.second;
            pq.pop();
            
            if(d > dist[u])continue;
            for(auto &it:adj[u]){
                int v = it.first;
                long long w = it.second;

                if(d+w < dist[v]){
                    dist[v] = d+w;
                    pq.push({dist[v],v});
                }
            }
        }

        for(int j=0;j<26;j++){
            if(dist[j] != LLONG_MAX)hashmap[i][j] = dist[j];
        }
    }

    long long findCost(string &source,string &target){
        int n = source.size();
        long long cost = 0;
        for(int i=0;i<n;i++){
            int u = source[i]-'a';
            int v = target[i]-'a';

            if(hashmap[u][v] == -1)return -1;

            cost += hashmap[u][v];
        }

        return cost;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<PII>> adj(26);
        int n = original.size();
        for(int i=0;i<n;i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            int w = cost[i];

            adj[u].push_back({v,w});
        }

        memset(hashmap,-1,sizeof(hashmap));

        for(int i=0;i<26;i++){
            if(adj[i].size() == 0){
                hashmap[i][i] = 0;
                continue;
            }
            solve(adj,i);
        }

        // for(int i=0;i<26;i++){
        //     cout<<i<<"->";
        //     for(int j=0;j<26;j++){
        //         cout<<hashmap[i][j]<<",";
        //     }
        //     cout<<endl;
        // }

        // for(int it=0;it<26;it++){
        //     cout<<it<<"->";
        //     for(auto p:adj[it]){
        //         cout<<"{"<<p.first<<","<<p.second<<"},";
        //     }
        //     cout<<endl;
        // }
        return findCost(source,target);
    }
};
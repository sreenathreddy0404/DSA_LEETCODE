// Problem link : https://leetcode.com/problems/jump-game-iv/description/
// Time complexity : O(n)
// Space complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>freq;

        for(int i=0;i<n;i++){
            freq[arr[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        vector<bool> visited(n,false);
        q.push({0,0});
        visited[0] = true;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int u = it.first;
            int steps = it.second;

            if(u == n-1)return steps;
            
            for(auto v:freq[arr[u]]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push({v,steps+1});
                }
            }
            freq[arr[u]].clear();
            if(u>0 && !visited[u-1]){
                visited[u-1] = true;
                q.push({u-1,steps+1});
            }
            if(u<n-1 && !visited[u+1]){
                visited[u+1] = true;
                q.push({u+1,steps+1});
            }
        }

        return n-1;
    }
};
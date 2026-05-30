// Problem Link: https://www.leetcode.com/problems/block-placement-queries/
// Time Complexity: O(nlogn + qlogn)
// Space Complexity:O(2e5)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N = 50000;
    vector<int> seg;

    void update(int idx,int val, int node, int low, int high){
        if(low == high){
            seg[node] = val;
            return;
        }

        int mid = low + (high-low)/2;

        if(idx <= mid){
            update(idx, val, 2*node+1, low, mid);
        }else{
            update(idx, val, 2*node+2, mid+1, high);
        }

        seg[node] = max(seg[2*node+1],seg[2*node+2]);
    }

    int query(int left, int right, int node, int low, int high){
        if(right < low || high < left)return 0;
        if(left <= low && high <= right)return seg[node];

        int mid = low+(high-low)/2;

        int leftVal = query(left, right, 2*node+1, low, mid);
        int rightVal = query(left, right, 2*node+2, mid+1, high); 

        return max(leftVal, rightVal);
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        seg.resize(4*N,0);
        set<int> st;
        st.insert(0);
        vector<bool> ans;
        for(auto &que : queries){
            if(que[0] == 1){
                int x = que[1];

                auto it = st.lower_bound(x);
                int curr = (it != st.end())?*it : -1;
                if(curr == x)continue;
                int pre = *prev(it);
                st.insert(x);

                update(x, x-pre, 0, 0, N-1);
                if(curr != -1)update(curr, curr-x, 0, 0, N-1);
            }else{
                int x = que[1];
                int sz = que[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int longestGap = query(0, pre, 0, 0, N-1);
                int best = max(longestGap, x-pre);

                ans.push_back(best >= sz);
            }
        }
        return ans;
    }
};
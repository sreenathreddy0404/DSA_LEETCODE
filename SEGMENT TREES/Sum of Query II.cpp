// Problem link : https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class SegmentTree{
    public:
        vector<int> seg;
        int n;
        
        SegmentTree(int arr[], int s){
            n = s;
            seg.assign(4*n, 0);
            build(arr, 0, 0, n-1);
        }
        
        void build(int arr[], int node, int left, int right){
            if(left == right){
                seg[node] = arr[left];
                return;
            }
            
            int mid = left + (right - left) / 2;
            
            build(arr, 2*node+1, left, mid);
            build(arr, 2*node+2, mid+1, right);
            
            seg[node] = seg[2*node+1] + seg[2*node+2];
        }
        
        int query(int node, int start, int end, int L, int R){
            if(L > end || R < start) return 0;
            
            if(L <= start && R >= end) return seg[node];
            
            int mid = start + (end - start) / 2;
            
            int left = query(2*node+1, start, mid, L, R);
            int right = query(2*node+2, mid+1, end, L, R);
            
            return left + right;
        }
        
        int rangeQuery(int L, int R){
            return query(0, 0, n-1, L, R);
        }
    };

    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        SegmentTree seg(arr, n);
        
        vector<int> ans;
        for(int i=0; i<q; i++){
            int L = queries[2*i]-1;
            int R = queries[2*i+1]-1;
            int sum = seg.rangeQuery(L, R);
            ans.push_back(sum);
        }
        
        return ans;
    }
};

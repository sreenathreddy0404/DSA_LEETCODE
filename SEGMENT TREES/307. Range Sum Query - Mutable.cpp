//problem link : https://leetcode.com/problems/range-sum-query-mutable/
//time complexity : O(log(N)) for both update and query
//space complexity : O(N)

#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    vector<int> seg;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        seg.resize(4*n,0);
        build(0,0,n-1);
    }

    void build(int node,int left,int right){
        if(left == right){
            seg[node] = nums[left];
            return;
        }

        int mid = left + (right-left)/2;

        build(2*node+1,left,mid);
        build(2*node+2,mid+1,right);

        seg[node] = seg[2*node+1] + seg[2*node+2];
    }
    
    void pointUpdate(int node,int left,int right,int idx,int val){
        if(left == right){
            seg[node] = val;
            return;
        }

        int mid = left + (right-left)/2;

        if(idx<=mid){
            pointUpdate(2*node+1,left,mid,idx,val);
        }else{
            pointUpdate(2*node+2,mid+1,right,idx,val);
        }

        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    void update(int index, int val) {
        pointUpdate(0,0,n-1,index,val);
    }
    
    int rangeSum(int node,int left,int right,int start,int end){
        if(right < start || left > end)return 0;
        if(start <= left && right <= end)return seg[node];

        int mid = left + (right-left)/2;

        int leftChild = rangeSum(2*node+1,left,mid,start,end);
        int rightChild = rangeSum(2*node+2,mid+1,right,start,end);

        return leftChild+rightChild;
    }
    int sumRange(int left, int right) {
       return rangeSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
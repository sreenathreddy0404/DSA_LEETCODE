#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<int> seg;
    int n;

    public:
    SegmentTree(vector<int>& arr){
        n = arr.size();
        seg.resize(4*n,0);
        build(arr,0,0,n-1);
    }

    //O(N)
    void build(vector<int>& arr,int node,int left,int right){
        if(left == right){
            seg[node] = arr[left];
            return;
        }

        int mid = left + (right - left)/2;

        build(arr, 2*node+1, left, mid);
        build(arr, 2*node+2, mid+1, right);

        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    // O(log(N))
    void update(int node, int left, int right, int idx, int val){
        if(left == right){
            seg[node] = val;
            return;
        }

        int mid = left + (right-left)/2;

        if(mid<=idx){
            update(2*node+1, left, mid, idx, val);
        }else{
            update(2*node+2, mid+1, right, idx, val);
        }
        
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    void pointUpdate(int idx, int val){
        update(0, 0, n-1, idx, val);
    }

    int query(int node, int start, int end,int L,int R){
        if(R < start || L > end)return 0;
        if(L <= start && end <= R)return seg[node];
        
        int mid = start + (end-start)/2;
        int left = query(2*node+1, start, mid, L, R);
        int right = query(2*node+2, mid+1, end, L, R);

        return left+right;
    }

    int rangeQuery(int L, int R){
        return query(0, 0, n-1, L, R);
    }
};

int main() {
    vector<int> arr = {0, 1, 3, 5, -2, 3};
    SegmentTree st(arr);

    cout << "Sum from 2 to 4: " << st.rangeQuery(2, 4) << endl;

    st.pointUpdate(3, 10);

    cout << "After update, sum from 2 to 4: "<< st.rangeQuery(2, 4) << endl;

    return 0;
}
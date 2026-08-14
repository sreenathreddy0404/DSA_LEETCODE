// problem Link : https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/
// Time Complexity : O(K*logn);
// space complexity : O(n);

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class SegmentTree{
    public:
        struct Node{
            public:
            int maxlen = 1;
            int prefix = 1;
            int suffix = 1;
        };

        vector<Node> seg;
        string s;
        int n;

        SegmentTree(string &s){
            this->s = s;
            this->n = s.size();

            seg.resize(4*n);
            build(0,0,n-1);
        }

        void merge(int node,int leftLen,int rightLen,int mid){
            int l = 2*node+1;
            int r = 2*node+2;

            //s[mid] = left part rightmost char
            //s[mid+1] = right part leftmost char
            if(s[mid] == s[mid+1]){
                //update maxlen
                seg[node].maxlen = max({seg[l].maxlen,seg[r].maxlen,seg[l].suffix + seg[r].prefix});

                //update prefix
                if(leftLen == seg[l].prefix){
                    seg[node].prefix = seg[l].prefix + seg[r].prefix;
                }else{
                    seg[node].prefix = seg[l].prefix;
                }

                //update suffix
                if(rightLen == seg[r].suffix){
                    seg[node].suffix = seg[r].suffix + seg[l].suffix;
                }else{
                    seg[node].suffix = seg[r].suffix;
                }
            }else{
                seg[node].maxlen = max(seg[l].maxlen,seg[r].maxlen);
                seg[node].prefix = seg[l].prefix;
                seg[node].suffix = seg[r].suffix;
            }
        }

        void build(int node,int left,int right){
            if(left == right)return;

            int mid = left + (right-left)/2;

            build(2*node+1,left,mid);
            build(2*node+2,mid+1,right);

            merge(node,mid-left+1,right-mid,mid);
        }

        void update(int node,int left,int right,int idx){
            if(left == right)return;

            int mid = left + (right-left)/2;

            if(idx <= mid){
                update(2*node+1,left,mid,idx);
            }else{
                update(2*node+2,mid+1,right,idx);
            }

            merge(node,mid-left+1,right-mid,mid);
        }
        void pointUpdate(int idx,char ch){
            s[idx] = ch;
            update(0,0,n-1,idx);
        }

        int getMaxLen(){
            return seg[0].maxlen;
        }
    };

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryCharacters.size();
        vector<int> ans(k,0);

        for(int i=0;i<k;i++){
            st.pointUpdate(queryIndices[i],queryCharacters[i]);
            ans[i] = st.getMaxLen();
        }   

        return ans;
    }
};
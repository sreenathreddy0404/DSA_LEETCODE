// Problem Link: https://leetcode.com/problems/two-best-non-overlapping-events/

// Approach: Greedy + Binary Search
// Time Complexity: O(N log N)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> prefix;
    int bs(vector<vector<int>>& events,int low,int high,int target){
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;

            if(events[mid][0]<target){
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1;
            }
        }

        if(ans == -1)return 0;
        return prefix[ans];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](vector<int>& e1,vector<int>& e2){
            if(e1[0] == e2[0])return e1[2]<e2[2];
            return e1[0]<e2[0];
        });

        int n = events.size();
        prefix.resize(n,0);
        prefix[n-1] = events[n-1][2];
        for(int i=n-2;i>=0;i--){
            prefix[i] = max(events[i][2],prefix[i+1]);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            int time = events[i][2];

            time += bs(events,i,n-1,events[i][1]+1);

            res = max(res,time);
        }
        return res;
    }
};
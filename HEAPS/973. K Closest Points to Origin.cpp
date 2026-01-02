// Problem Link: https://leetcode.com/problems/k-closest-points-to-origin/
// Time Complexity : O(N log N) where N is the number of points
// Space Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef pair<int,vector<int>> PIV;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<PIV,vector<PIV>,greater<PIV>> pq;

        for(auto &point:points){
            int x1 = point[0];
            int y1 = point[1];

            int d = x1*x1 + y1*y1;
            pq.push({d,point});
        }

        vector<vector<int>> ans;
        while(k != 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
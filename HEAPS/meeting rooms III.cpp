//problem Like: https://leetcode.com/problems/meeting-rooms-ii/description/
// Approach: Min-Heap
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<long long,long long> PII;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        int m = meetings.size();

        vector<int> count(n,0);
        priority_queue<int,vector<int>,greater<int>> available;
        for(int i=0;i<n;i++)available.push(i);
        for(int i=0;i<m;i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            int duration = end-start;

            while(!pq.empty() && pq.top().first <= start){
                available.push(pq.top().second);
                pq.pop();
            }

            if(!available.empty()){
                int room = available.top();available.pop();
                pq.push({end,room});
                count[room]++;
            }else{
                auto temp = pq.top();pq.pop();
                pq.push({temp.first+duration,temp.second});
                count[temp.second]++;
            }
        }

        int max_booked = 0;
        for(int i=0;i<n;i++){
            if(count[max_booked] < count[i]){
                max_booked = i;
            }
        }

        return max_booked;
    }
};
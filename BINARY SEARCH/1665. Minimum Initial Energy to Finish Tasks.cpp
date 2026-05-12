// Problem Link : https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>>& tasks, int energy){
        int n = tasks.size();
        for(int i=0;i<n;i++){
            if(energy >= tasks[i][1]){
                energy -= tasks[i][0];
            }else{
                return false;
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& task1,vector<int>& task2){
            return task1[1]-task1[0] > task2[1]-task2[0];
        });
        int n = tasks.size();

        int low = tasks[0][1];
        int high = 0;
        for(int i=0;i<n;i++){
            high += tasks[i][1];
        }

        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(tasks,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
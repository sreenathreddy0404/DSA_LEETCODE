//problem link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/


// Approach1: Binary Search
// Time Complexity: O(N log M) where N is number of rows and M is number of columns
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bs(vector<int>& grid){
        int m = grid.size();
        int l=0;
        int h=m-1;
        int ans = m;
        while(l<=h){
            int mid = l+(h-l)/2;

            if(grid[mid] < 0){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }

        return m-ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        for(int i=0;i<n;i++){
            count += bs(grid[i]);
        }
        return count;
    }
};

// Approach2: Optimal Approach (Staircase method)
// Time Complexity: O(N + M) where N is number of rows and M is number
// Space Complexity: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;
        int i = n-1;
        int j = 0;

        while(i>=0 && j<m){
            if(grid[i][j] < 0){
                res += m-j;
                i--;
            }else{
                j++;
            }
        }

        return res;
    }
};
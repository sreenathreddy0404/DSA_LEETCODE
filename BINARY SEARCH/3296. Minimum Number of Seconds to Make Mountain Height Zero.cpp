// problem link : https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/
// Time complexity : O(n * log(max_time)) where n is the number of workers and max_time is the maximum time taken by a worker to reduce the mountain height by 1
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   bool check(int mountainHeight, vector<int>& workerTimes, long long seconds){
        long long height = 0;

        for(int t : workerTimes){
            long double x = (long double)seconds / t;
            long long k = (sqrtl(1 + 8*x) - 1) / 2;
            height += k;
        }

        return height >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        long long high = LLONG_MAX-1;

        long long ans = -1;
        while(low <= high){
            long long mid = low+(high-low)/2;

            if(check(mountainHeight,workerTimes,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};
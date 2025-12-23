// Problem Link: https://leetcode.com/problems/reducing-dishes/
#include <bits/stdc++.h>
using namespace std;

//Approach:Greedy
//DP soultion in dp folder
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        if(satisfaction[n-1] <= 0)return 0;
        
        //suffix from back
        vector<int> suffix(n,0);
        suffix[n-1] = satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]+satisfaction[i];
        }

        //one one from the last to get maximum
        // [5] -> 5 (i == n-1) = 5
        // [0,5]-> 5+suffix[i+1]+nums[i]; (i == n-2) = 10
        // [-1,0,5] => 14
        // [-8,-1,0,5] => 10 stop here
        int prev = satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            int curr = prev + suffix[i+1] + satisfaction[i];
            if(curr <= prev)break;
            prev = curr;
        }
        return prev;
    }
};
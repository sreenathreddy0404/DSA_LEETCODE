//problem link: https://leetcode.com/problems/maximum-happiness-of-selected-children/description/
// Approach: Greedy
// Time Complexity: O(N log N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());

        long long result = 0;
        for(int i=0;i<k;i++){
            if(happiness[i]-i <= 0)break;
            result += happiness[i]-i;
        }

        return result;
    }
};
// Problem link : https://www.leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n = cost.size();
        int totalCost = 0;
        int i = n-1;

        while(i>=0){
            totalCost += cost[i];
            if(i>0)totalCost += cost[i-1];
            i -= 3;
        }
        return totalCost;
    }
};
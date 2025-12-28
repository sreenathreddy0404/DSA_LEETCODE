//problem link: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description/
// Time Complexity: O(1)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long total = 1LL*cost1 + cost2;
        long long both = 1LL*costBoth;

        long long res = 0;
        if(total > both){
            int mini = min(need1,need2);
            res = both*mini;
            need1-=mini;
            need2-=mini;
        }
        res += 1LL*need1*min(cost1,costBoth);
        res += 1LL*need2*min(cost2,costBoth);
        return res;
    }
};
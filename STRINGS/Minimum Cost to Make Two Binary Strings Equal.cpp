//problem link: https://leetcode.com/problems/minimum-cost-to-make-two-binary-strings-equal/
//Time Complexity: O(n)
//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.length();

        long long countA = 0;
        long long countB = 0;
        for(int i=0;i<n;i++){
            if(s[i] != t[i]){
                if(s[i] == '0')countA++;
                else countB++;
            }
        }

        long long pairFix = min(swapCost, 2*flipCost);

        long long pairs = min(countA,countB);

        long long rem = abs((long long)countA-(long long)countB);

        long long totalcost = (pairs * pairFix);

        long long remainingPairs = rem/2;

        totalcost += 1LL*remainingPairs*min(swapCost + crossCost,2*flipCost);

        if(rem % 2 != 0)totalcost += flipCost;

        return totalcost;
    }
};
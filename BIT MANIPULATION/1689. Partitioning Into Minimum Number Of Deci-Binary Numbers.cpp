// Problem link : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description
// Time complexity : O(N)
// Space complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(auto ch:n){
            ans = max(ans,(ch-'0'));
        }
        return ans;
    }
};
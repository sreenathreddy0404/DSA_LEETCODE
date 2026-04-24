//Problem Link : https://leetcode.com/problems/furthest-point-from-origin/
//Time Complexity : O(n)
//Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int lCount = 0;
        int rCount = 0;
        int dCount = 0;
        for(int i=0;i<n;i++){
            if(moves[i] == 'L')lCount++;
            else if(moves[i] == 'R')rCount++;
            else dCount++;
        }

        return max(abs(lCount-rCount-dCount),abs(lCount-rCount+dCount));
    }
};
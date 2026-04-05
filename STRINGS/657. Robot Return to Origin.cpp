// problem link : https://leetcode.com/problems/robot-return-to-origin/
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0;
        int v = 0;

        for(auto &ch:moves){
            if(ch == 'L')h++;
            else if(ch == 'R')h--;
            else if(ch == 'U')v++;
            else v--;
        }

        return h == 0 && v == 0;
    }
};
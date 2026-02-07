// dp solution exists in dp folder
// problem link : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description
// time complexity : O(N);
// space complexity : O(1);

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        int flips = 0;
        int bCount = 0;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i] == 'b'){
                bCount++;
            }else{
                flips = min(bCount,1+flips);
            }
        }

        return flips;
    }
};
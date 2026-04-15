// Problem Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for(int i=0;i<n;i++){
            int ind1 = (startIndex+i)%n;
            int ind2 = (startIndex-i+n)%n;
            if(words[ind1] == target || words[ind2] == target){
                return i;
            }
        }

        return -1;
    }
};
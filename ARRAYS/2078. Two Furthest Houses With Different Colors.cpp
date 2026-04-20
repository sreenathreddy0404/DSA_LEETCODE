// problem link : https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = -1;
        int i = 0;
        int j = n-1;
        while(colors[i] == colors[j])j--;
        ans = max(ans,j-i);
        j = n-1;
        while(colors[i] == colors[j])i++;
        ans = max(ans,j-i);
        return ans;
    }
};
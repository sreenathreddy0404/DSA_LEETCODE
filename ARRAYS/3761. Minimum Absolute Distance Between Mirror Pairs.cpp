// Problem link : https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int n){
        int num = 0;
        while(n > 0){
            num = (num*10) + (n%10);
            n = n/10;
        }
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,deque<int>> mp;
        vector<int> mirror(n,0);
        for(int i=0;i<n;i++){
            mirror[i] = reverse(nums[i]);
            mp[nums[i]].push_back(i);
        }

        int res = INT_MAX;
        for(int i=0;i<n;i++){
            int key = mirror[i];
            mp[nums[i]].pop_front();
            if(mp[key].size() > 0){
                res = min(res,mp[key].front()-i);
            }
        }

        if(res == INT_MAX)return -1;
        return res;
    }
};
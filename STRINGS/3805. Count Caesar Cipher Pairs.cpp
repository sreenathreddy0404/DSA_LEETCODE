// problem link : https://leetcode.com/problems/count-caesar-cipher-pairs/
// time complexity: O(n*m)
// space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        
        long long count = 0;
        unordered_map<string,int> um;
        
        for(int i=0;i<n;i++){
            int shift = words[i][0]-'a';
            string common = words[i];

            for(int j=0;j<m;j++){
                int dis = common[j]-'a';
                int newShift = (dis-shift + 26)%26;
                common[j] = char(newShift + 'a');
            }

            count += um[common];
            um[common]++;
        }

        return count;
    }
};
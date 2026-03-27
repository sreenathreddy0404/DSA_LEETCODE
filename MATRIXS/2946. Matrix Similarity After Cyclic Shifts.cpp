// Problem Link : https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
// Time Complexity: O(n * m)
// Space Complexity: O(m)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k = k%m;
        int k1 = m-k;
        
        for(int i=0;i<n;i++){
            vector<int> arr = mat[i];

            if(i%2 == 0){
                reverse(arr.begin(),arr.begin()+k);
                reverse(arr.begin()+k,arr.end());
                reverse(arr.begin(),arr.end());
            }else{
                reverse(arr.begin(),arr.begin()+k1);
                reverse(arr.begin()+k1,arr.end());
                reverse(arr.begin(),arr.end());
            }

            if(arr!= mat[i])return false;
        }
        return true;
    }
};
// Problem link : https://leetcode.com/problems/construct-product-matrix/
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int size = n*m;

        vector<int> arr(size,1);
        int k = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[k++] = grid[i][j]%mod;
            }
        }

        vector<int> prefix(size,1);
        vector<int> suffix(size,1);

        for(int i=1;i<size;i++){
            prefix[i] = (prefix[i-1]*arr[i-1])%mod;
        }

        for(int i=size-2;i>=0;i--){
            suffix[i] = (suffix[i+1]*arr[i+1])%mod;
        }

        vector<vector<int>> p(n,vector<int>(m));
        k = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p[i][j] = (prefix[k] * suffix[k])%mod;
                k++;
            }
        }

        return p;
    }
};
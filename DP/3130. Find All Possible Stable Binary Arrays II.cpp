// Problem link : https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description
// Time Complexity : O(N*M) where N is the number of zeros and M is the number of ones
// Space Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[1001][1001][3];
    // int mod = 1e9+7;
    // int solve(int zero,int one,int limit,int last){
    //     if(zero == 0 && one == 0){
    //         return 1;
    //     }

    //     if(dp[zero][one][last] != -1)return dp[zero][one][last];

    //     long long ans = 0;
    //     if(last != 1){
    //         for(int i = 1;i<=limit && i<=one;i++){
    //             ans = (ans + solve(zero,one-i,limit,1))%mod;
    //         }
    //     }

    //     if(last != 0){
    //         for(int i=1;i<=limit && i<=zero;i++){
    //             ans = (ans + solve(zero-i,one,limit,0))%mod;
    //         }
    //     }

    //     return dp[zero][one][last] =  (ans)%mod;
    // }
  int numberOfStableArrays(int zero, int one, int limit) {
    const int MOD = 1e9 + 7;

    vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
    vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

    for(int i = 1; i <= min(zero, limit); i++)
        dp0[i][0] = 1;

    for(int j = 1; j <= min(one, limit); j++)
        dp1[0][j] = 1;

    for(int i = 1; i <= zero; i++) {
        for(int j = 1; j <= one; j++) {

            dp0[i][j] = (dp0[i-1][j] + dp1[i-1][j]) % MOD;
            if(i - limit - 1 >= 0)
                dp0[i][j] = (dp0[i][j] - dp1[i-limit-1][j] + MOD) % MOD;

            dp1[i][j] = (dp0[i][j-1] + dp1[i][j-1]) % MOD;
            if(j - limit - 1 >= 0)
                dp1[i][j] = (dp1[i][j] - dp0[i][j-limit-1] + MOD) % MOD;
        }
    }

    return (dp0[zero][one] + dp1[zero][one]) % MOD;
}  
};
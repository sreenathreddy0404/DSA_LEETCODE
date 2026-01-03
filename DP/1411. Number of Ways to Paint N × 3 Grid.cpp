//problem link : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
//Time Complexity : O(N) where N is the number of rows
//Space Complexity : O(N) for dp array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int numOfWays(int n) {
        vector<int> dp(n,0);
        dp[0] = 12; //if there is only one row then there is 12 possibilities
        int same = 6;//there are six two same color boxes;
        int diff = 6;//there are six all diff color boxes;

        for(int i=1;i<n;i++){
            //we can arrange only 5 boxes under the same color boxes
            //we can arrange only 4 boxes under the diff color boxes
            //total boxes = 5*same + 4*different

            dp[i] = (1LL*5*same + 1LL*4*diff)%mod;

            //in the 5 boxes there are 3 same color boxes and 2 diff color boxes
            //in the 4 boxes there are 2 same color boxes and 2 diff color boxes
            int s = (1LL*3*same + 2*diff)%mod;
            int d = (1LL*2*same + 2*diff)%mod;

            same = s;
            diff = d;
        }

        return dp[n-1];
    }
};


//Optimized Space Complexity : O(1)
class Solution {
public:
    int mod = 1e9+7;
    int numOfWays(int n) {
        //if there is only one row then there is 12 possibilities
        int same = 6;//there are six two same color boxes;
        int diff = 6;//there are six all diff color boxes;

        for(int i=1;i<n;i++){
            int s = (1LL*3*same + 2*diff)%mod;
            int d = (1LL*2*same + 2*diff)%mod;

            same = s;
            diff = d;
        }

        return (same + diff)%mod;
    }
};

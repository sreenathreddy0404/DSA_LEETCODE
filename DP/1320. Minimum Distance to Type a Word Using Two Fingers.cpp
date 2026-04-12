// Problem link : https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
// Time Complexity: O(N*26*26)
// Space Complexity: O(N*26*26)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> layout;
    int dp[302][27][27];

    void createLayout(){
        layout.resize(26);
        int k = 0;
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                layout[k++] = {i,j};
                if(k == 26)return;
            }
        }
    }

    //ffPos = first fingerPosition
    //sfPos = second fingerPosition
    int helper(string &word,int ffPos,int sfPos,int i){
        if(i >= word.size())return 0;
        if(dp[i][ffPos+1][sfPos+1] != -1)return dp[i][ffPos+1][sfPos+1];
        int pos = word[i]-'A';

        int res = INT_MAX;
        if(ffPos == -1){
            res = min(res, 0 + helper(word,pos,sfPos,i+1));
        }else{
            int x1 = layout[pos].first;
            int y1 = layout[pos].second;

            int x2 = layout[ffPos].first;
            int y2 = layout[ffPos].second;

            int dist = abs(x1-x2) + abs(y1-y2);

            res = min(res,dist + helper(word,pos,sfPos,i+1));

            if(sfPos == -1){
                res = min(res, 0 + helper(word,ffPos,pos,i+1));
            }else{
                int x3 = layout[sfPos].first;
                int y3 = layout[sfPos].second;

                int dist = abs(x1-x3) + abs(y1-y3);

                res = min(res, dist + helper(word,ffPos,pos,i+1));
            }
        }

        return dp[i][ffPos+1][sfPos+1] = res;
    }
    int minimumDistance(string word) {
        createLayout();
        // for(int i=0;i<26;i++){
        //     cout<<layout[i].first<<" "<<layout[i].second<<endl;
        // }
        memset(dp,-1,sizeof(dp));

        return helper(word,-1,-1,0);
    }
};
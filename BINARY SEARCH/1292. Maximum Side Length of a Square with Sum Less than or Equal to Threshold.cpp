//problem link: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
//time complexity: O(n*m*log(min(n,m)))
//space complexity: O(n*m)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool check(vector<vector<int>>& prefix,int i,int j,int offset,int threshold){
        int x = i+offset;
        int y = j+offset;

        int totalSum = prefix[x][y];
        if(i!=0)totalSum -= prefix[i-1][y];
        if(j!=0)totalSum -= prefix[x][j-1];
        if(i!=0 && j!=0)totalSum += prefix[i-1][j-1];

        return totalSum <= threshold;
    }

    bool possible(vector<vector<int>> &prefix,int offset,int threshold){
        int n = prefix.size();
        int m = prefix[0].size();

        for(int i=0;i<n-offset;i++){
            for(int j=0;j<m-offset;j++){
                if(check(prefix,i,j,offset,threshold)){
                    return true;
                }
            }
        }

        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)prefix[i][j] = mat[i][j];
                else if(i==0)prefix[i][j] = prefix[i][j-1] + mat[i][j];
                else if(j==0)prefix[i][j] = prefix[i-1][j] + mat[i][j];
                else prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i][j];

                // cout<<prefix[i][j]<<" ";
            }
            // cout<<endl;
        }

        int ans = 0;
        int low = 1;
        int high = min(n,m);

        while(low<=high){
            int mid = low + (high-low)/2;

            if(possible(prefix,mid-1,threshold)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};
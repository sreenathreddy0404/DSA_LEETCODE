//Problem Link : https://leetcode.com/problems/rotate-the-box/
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> newGrid(m,vector<char>(n,'.'));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newGrid[j][n-i-1] = boxGrid[i][j];
            }
        }

        for(int j=0;j<n;j++){
            int stones = 0;
            for(int i=0;i<m;i++){
                if(newGrid[i][j] == '#'){
                    stones++;
                    newGrid[i][j] = '.';
                }else if(newGrid[i][j] == '*'){
                    int k = i-1;
                    while(k>=0 && stones>0){
                        newGrid[k][j] = '#';
                        k--;
                        stones--;
                    }
                }
            }
            int k = m-1;
            while(k>=0 && stones>0){
                newGrid[k][j] = '#';
                k--;
                stones--;
            }
        }
        return newGrid;
    }
};
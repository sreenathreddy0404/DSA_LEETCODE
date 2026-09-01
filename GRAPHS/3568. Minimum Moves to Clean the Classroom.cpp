//problem link : https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/description/
//Time complexity : O(n*m*2^10)
//space complexity : O(n*m*2^10)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        map<pair<int,int>,int> litterMap;
        int litterCount = 0;
        int startX = -1;
        int startY = -1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j] == 'S'){
                    startX = i;
                    startY = j;
                }else if(classroom[i][j] == 'L'){
                    litterMap[{i,j}] = litterCount++;
                }
            }
        }

        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        int targetMask = (1 << litterCount) - 1;
        int steps = 0;

        queue<tuple<int,int,int,int>> q;
        q.push({startX,startY,0,energy});

        vector<vector<vector<int>>> bestEnergy (n, vector<vector<int>>(m, vector<int>((1<<litterCount), -1)));
        bestEnergy[startX][startY][0] = energy;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto [x, y, mask, e] = q.front();
                q.pop();

                if(mask == targetMask) return steps;

                for(auto &d : dirs){
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || classroom[nx][ny] == 'X')continue;

                    int ne = e-1;
                    if(ne < 0)continue;
                    int newMask = mask;

                    if(classroom[nx][ny] == 'L'){
                        newMask |= (1 << litterMap[{nx,ny}]);
                    }else if(classroom[nx][ny] == 'R'){
                        ne = energy;
                    }

                    if(bestEnergy[nx][ny][newMask] < ne){
                        bestEnergy[nx][ny][newMask] = ne;
                        q.push({nx,ny,newMask,ne});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
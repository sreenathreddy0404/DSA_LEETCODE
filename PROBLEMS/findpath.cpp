#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
int totalCells;
int row,col;

vector<vector<int>> dirs = {{0,-1},{-1,0},{0,1},{1,0}};
bool solve(int i,int j, vector<vector<bool>>& visited, vector<vector<int>>& result, vector<vector<int>>& layout, int window, int maxwindow, int visitedCells){
    if(visitedCells >= totalCells){
        ans = result;
        return true;
    }
    
    for(auto &d : dirs){
        int ni = i+d[0];
        int nj = j+d[1];
        
        if(ni < 0 || ni >= row || nj < 0 || nj >= col || visited[ni][nj] || (layout[ni][nj] != 0 && layout[ni][nj] != maxwindow))continue;
        
        visited[ni][nj] = true;
        result.push_back({ni,nj});
        
        if(solve(ni,nj,visited,result,layout,window,(layout[ni][nj] == maxwindow)? maxwindow+1:maxwindow, visitedCells+1))return true;
        
        visited[ni][nj] = false;
        result.pop_back();
    }
    return false;
}

vector<vector<int>> findPath(vector<vector<int>> &layout, int window){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(layout[i][j] != 0 && layout[i][j] != 1)continue;
            vector<vector<int>> result;
            result.push_back({i,j});
            vector<vector<bool>> visited(row,vector<bool>(col,false));
            visited[i][j] = true;
            if(solve(i, j, visited, result, layout, window, layout[i][j]+1, 1))return ans;
        }
    }
    return {};
}
int main(){
    row = 3;
    col = 2;
    totalCells = row * col;
    vector<vector<int>> layout = {{0,2},{1,0},{0,3}};
    int window = 3;
    vector<vector<int>> result = findPath(layout,window);
    
    for(auto &cell : result){
        cout<<cell[0]<<" "<<cell[1]<<endl;
    }
}
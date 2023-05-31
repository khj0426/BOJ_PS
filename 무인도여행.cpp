#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char map[101][101];
bool visited[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n,m;
int depth = 0;
void dfs(int x,int y){
    visited[x][y] = true;
    depth += (map[x][y] - '0');
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            continue;
        }
        if(visited[nx][ny] == false){
            if(map[nx][ny] - '0' >= 1 && map[nx][ny] - '0' <= 9){
                dfs(nx,ny);
            }
        }
    }
    
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    m = maps[0].size();
    for(int i = 0;i<maps.size();i++){
        for(int j = 0;j<maps[i].size();j++){
            map[i][j] = maps[i][j];
        }
       
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] == false){
                if(map[i][j] - '0' >= 1 && map[i][j] - '0' <= 9){
                    depth = 0;
                    dfs(i,j);
                answer.push_back(depth);    
            }
        }
    }
}
    
    sort(answer.begin(),answer.end());
    if(answer.size() == 0){
        answer.push_back(-1);
    }
        
    
    
    return answer;
}
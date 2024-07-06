#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> maps) {
    
    int ans = 987654321;
    int visited[101][101];
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};

    int answer = 0;
    queue<pair<int,int>> q;
    int startX,startY;
    
    int lX,lY;
    
    int endX,endY;
    for(int i = 0;i<maps.size();i++){
        for(int j = 0;j<maps[i].size();j++){
            visited[i][j] = ans;  
            if(maps[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            
            if(maps[i][j] == 'L'){
                lX = i;
                lY = j;
            }
            
            if(maps[i][j] == 'E'){
                endX = i;
                endY = j;
            }
        }
    }
    
    
    
    //Start -> 레버
    
    q.push({startX,startY});
    visited[startX][startY] = 0;
    
    while(!q.empty()){
        pair<int,int> p = q.front();
        int val = visited[p.first][p.second];
        if(p.first == lX && p.second == lY){
            answer = answer + val;
            break;
        }
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(nx >= maps.size() || nx < 0 || ny >= maps[0].size() || ny < 0){
                continue;
            }
            if(maps[nx][ny] == 'X'){
                continue;
            }
            if(val + 1 < visited[nx][ny]){
                visited[nx][ny] = val + 1;
                q.push({nx,ny});
            }
        }
    }
    
    //레버로 못가는 경우
    if(answer == 0){
        return -1;
    }
    
    //레버 -> End
    
     for(int i = 0;i<maps.size();i++){
        for(int j = 0;j<maps[i].size();j++){
            visited[i][j] = ans;  
        }
    }
    
    q.push({lX,lY});
    visited[lX][lY] = 0;
    
    while(!q.empty()){
        pair<int,int> p = q.front();
        if(p.first == endX && p.second == endY){
            answer = answer + visited[endX][endY];
            break;
        }
        int val = visited[p.first][p.second];
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(nx >= maps.size() || nx < 0 || ny >= maps[0].size() || ny < 0){
                continue;
            }
            
            if(maps[nx][ny] == 'X'){
                continue;
            }
            if(val + 1 < visited[nx][ny]){
                visited[nx][ny] = val + 1;
                q.push({nx,ny});
            }
            
        }
        
        
    }
   
    if(visited[endX][endY] == ans){
        return -1;
    }
    return answer;
}
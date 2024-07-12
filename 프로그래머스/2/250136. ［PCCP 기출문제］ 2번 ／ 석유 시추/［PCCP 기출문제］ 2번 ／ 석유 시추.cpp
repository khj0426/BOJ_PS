#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

int arr[501][501];
bool visited[501][501];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};



int solution(vector<vector<int>> land) {
    int answer = 0;
    int area_Count = 1;
    //먼저 영역별로 번호를 주자 1번부터 시작.
    //영역별 넓이저장
    map<int,int> m;
    map<int,int>::iterator iter;
    
    
    
    queue<pair<int,int>> q;
    for(int i = 0;i<land.size();i++){
        for(int j = 0;j<land[i].size();j++){
            //석유가 있다면 아직 영역이 없다면
            if(land[i][j] == 1 && arr[i][j] == 0){
                land[i][j] = 99;
                arr[i][j] = area_Count;
                q.push({i,j});
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    arr[x][y] = area_Count;
                    m[area_Count]++;
                    for(int z = 0;z<4;z++){
                        int nx = x + dx[z];
                        int ny = y + dy[z];
                        if(nx < 0 || nx >= land.size() || ny < 0 || ny >= land[0].size()){
                            continue;
                        }
                        if(land[nx][ny] == 1 && visited[nx][ny] == false && arr[nx][ny] == 0){
                            q.push({nx,ny});
                            arr[nx][ny] = area_Count;
                            visited[nx][ny] = true;
                        } 
                    }
                }
                area_Count++;
            }
        }
    }
    
    
    
   
    
    //시추
    int maxCount = -987654321;
    for(int i = 0;i<land[0].size();i++){
        map<int,int> areas;
        int count = 0;
        for(int j = 0;j<land.size();j++){
            if(arr[j][i] == 0){
                continue;
            }
            else{
                iter = areas.find(arr[j][i]);
                if(iter == areas.end()){
                    count += m[arr[j][i]];
                    areas[arr[j][i]] = 1;
                }
                else{
                    continue;
                }
            }
        }
        maxCount = max(count,maxCount);
  
    }
    
    
    
    answer = maxCount;
    return answer;
}
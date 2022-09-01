#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
char map[51][51];
int dt[51][51];
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int ans = -1;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
void init(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            dt[i][j] = -1;
            cin >> map[i][j];
        }
    }
}

void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    dt[x][y] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(dt[nx][ny] == -1 && map[nx][ny] == 'L'){
                dt[nx][ny] = dt[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(void){
    init();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(map[i][j] == 'L'){
                for(int k = 0;k<n;k++){
                    for(int q = 0;q<m;q++){
                        dt[k][q] = -1;
                    }
                }
                
                bfs(i,j);
                for(int k = 0;k<n;k++){
                    for(int q = 0;q<m;q++){
                        ans = max(ans,dt[k][q]);
                    }
                }
            }
        }
    }
    
     cout << ans;
    
    
}


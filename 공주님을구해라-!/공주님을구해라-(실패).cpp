#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int n,m,t;
int map[101][101];
int draw_x,draw_y;
bool is_not_valid = false;
int dt[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int time_ = 0;
int direct_time = 0;
int ans = 987654321;
 
void init(){
    cin >> n >> m >> t;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                draw_x = i;
                draw_y = j;
            }
            dt[i][j] = -1;
        }
    }
}
//그림 무시하고 최단 경로
 
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    dt[x][y] = 0;
 
    while(!q.empty()){
        int cur = q.size();
        for(int i = 0;i<cur;i++){
            int x = q.front().first;
            int y = q.front().second;
            if(x == n-1 && y == m-1){
                return;
            }
            q.pop();
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                    continue;
                }
                if(dt[nx][ny] == -1 && map[nx][ny] != 1 && map[nx][ny] != 2){
                    q.push({nx,ny});
                    dt[nx][ny] = dt[x][y] + 1;
                }
            }
        }
 
       direct_time++;
    }
}

void BFS(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
 
    while(!q.empty()){
        int cur = q.size();
        for(int i = 0;i<cur;i++){
            int x = q.front().first;
            int y = q.front().second;
             q.pop();
            if(x == n-1 && y == m-1){
                return;
            }
           
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                    continue;
                }
                if(dt[nx][ny] == -1){
                    q.push({nx,ny});
                    dt[nx][ny] = dt[x][y] + 1;
                }
            }
        }
 
       time_++;
    }
}
 
//그림 -> 공주로 가는 경우
void to_draw(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    if(x == draw_x && y == draw_y){
                is_not_valid = true;
            }
    dt[x][y] = 0;
 
    while(!q.empty()){
        int cur = q.size();
        for(int i = 0;i<cur;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == draw_x && y == draw_y){
                return;
            }
 
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                    continue;
                }
                if(dt[nx][ny] == -1 && map[nx][ny] != 1){
                    q.push({nx,ny});
                    dt[nx][ny] = dt[x][y] + 1;
                }
            }
        }
 
       time_++;
    }
 
}
 
int main(void){
    init();
 
    bfs(0,0);
    
    if(direct_time <= t){
        if(dt[n-1][m-1] != -1){
            if(direct_time < ans){
                ans = direct_time;
            }
        }
    }
    //그림 거쳐서 가는 경우
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            dt[i][j] = -1;
        }
    }
 
    to_draw(0,0);//그림 거쳐서
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i != draw_x && j != draw_y){
                dt[i][j] = -1;
            }
        }
    }
    BFS(draw_x,draw_y);
 
    if(dt[n-1][m-1] != -1 && time_ <= ans && time_ <= t){
        ans = time_;
    }
    if(ans == 987654321){
        cout << "Fail";
    }
    else{
        cout << ans;
    }
 
 
 
}
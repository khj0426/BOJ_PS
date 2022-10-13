#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int direct_distance = 0;
int draw_distance = 0;
int n,m,t;
int dt[103][103];
int map[103][103];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int draw_x,draw_y;
 
void init(){
    cin >> n >> m >> t;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            dt[i][j] = -1;
            if(map[i][j] == 2){
                draw_x = i;
                draw_y = j;
            }
        }
    }
}
 
void direct_bfs(int x,int y){ //벽 안부수고 바로 경로로 가는 경우
    queue<pair<int,int>> q;
    q.push({x,y});
    dt[x][y] = 0;
 
    while(!q.empty()){
        int cursize = q.size();
        for(int i = 0;i<cursize;i++){
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
                if(map[nx][ny] == 0){
                    if(dt[nx][ny] == -1){
                        dt[nx][ny] = dt[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        direct_distance++;
    }
}
 
void to_draw(int x,int y){ //그람으로 가는 경우
    queue<pair<int,int>> q;
    q.push({x,y});
    dt[x][y] = 0;
 
    while(!q.empty()){
        int cursize = q.size();
        for(int i = 0;i<cursize;i++){
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
                if(map[nx][ny] == 0){
                    if(dt[nx][ny] == -1){
                        dt[nx][ny] = dt[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
                else if(map[nx][ny] == 2){
                    if(dt[nx][ny] == -1){
                        dt[nx][ny] = dt[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        draw_distance++;
    }
}
 
void to_nm(int x,int y){ //그람에서 경로로 가는 경우
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i != draw_x && j != draw_y){
                dt[i][j] = -1;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int cursize = q.size();
        for(int i = 0;i<cursize;i++){
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
 
                    if(dt[nx][ny] == -1){
                        dt[nx][ny] = dt[x][y] + 1;
                        q.push({nx,ny});
                    }
 
            }
        }
        draw_distance++;
    }
 
 
}
 
int main(void){
    init();
    bool direct_ = false; //곧바로 갈 수 있는 경우 true
    bool draw_ = false; //그람 거쳐서 갈 수 있는 경우 true
    direct_bfs(0,0);
    if(dt[n-1][m-1] != -1){
        if(direct_distance <= t){
            direct_ = true;
        }
    }
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            dt[i][j] = -1;
        }
    }
 
    to_draw(0,0);
    if(dt[draw_x][draw_y] != -1){ //그럼거쳐서 가는 경우
        to_nm(draw_x,draw_y);
        if(dt[n-1][m-1] != -1 && draw_distance <= t){
            draw_ = true;
        }
    }
 
    if(draw_ == false && direct_ == false){
        //둘다 도달할 수 없는 경우
        cout << "Fail";
    }
    else if(draw_ == true && direct_ == false){
        //그림을 얻어서 갈 수 있는 경우 + 직접 가는 경로가 없는 경우
        cout << draw_distance;
    }
    else if(draw_ == false && direct_ == true){
        //그림을 얻어서 갈수 없는 경우 + 직접 가는 경로가 존재 하는 경우
        cout << direct_distance;
    }
    else{

        //둘다 가능한 경우(최소값으로)
        cout << min(draw_distance,direct_distance);
    }
 
}






#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
 
int escape_time = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int dt[1001][1001];
char map[1001][1001];
int r,c;
int startx,starty;
vector<pair<int,int>> v; //불이 시작되는 위치->여러개
 
 
void init(){
    cin >> r >> c;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
            dt[i][j] = -1;
            if(map[i][j] == 'F'){
                v.push_back({i,j});
            }
            else if(map[i][j] == 'J'){
                startx = i;
                starty = j;
            }
        }
    }
}
 
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    dt[x][y] = escape_time;
    while(!q.empty()){
        vector<pair<int,int>> new_v;
 
        for(int i = 0;i<v.size();i++){
            int Fx = v[i].first;
            int Fy = v[i].second;
            for(int j = 0;j<4;j++){
                int Fnx = Fx + dx[j];
                int Fny = Fy + dy[j];
                if(Fnx < 0 || Fny < 0 || Fnx >= r || Fny >= c){
                    continue;
                }
                if(map[Fnx][Fny] != '#'){
                    if(map[Fnx][Fny] == 'F'){
                        continue;
                    }
                    map[Fnx][Fny] = 'F';
                    new_v.push_back({Fnx,Fny});
                }
            }
        }
        v.clear();
        v = new_v;
 
        int cursize = q.size();
        for(int i = 0;i<cursize;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= r || ny >= c){
                    continue;
                }
                if(map[nx][ny] == '.'){
                    if(dt[nx][ny] == -1){
                        dt[nx][ny] = escape_time + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        escape_time++;
    }
 
 
}
int main(void){
    init();
    bfs(startx,starty);
    int ans = 987654321;
 
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(i == 0 || i == r-1 || j == 0 || j == c-1){
                if(dt[i][j] != -1){
                    ans = min(ans,dt[i][j] + 1);
                }
            }
        }
    }
    if(ans == 987654321){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans; 
}

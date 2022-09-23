#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int TIME = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int dt[101][101][3];
char map[101][101];
int time_[101][101][3];
int n,m;
vector<pair<int,int>> v;
 
struct infomation{
    int x;
    int y;
    int data;
};
 
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
 
typedef struct infomation info;
 
void init(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            dt[i][j][0] = -1;
            dt[i][j][1] = -1;
            dt[i][j][2] = -1;
            time_[i][j][0] = 0;
            time_[i][j][1] = 0;
            time_[i][j][1] = 0;
        }
    }
 
    for(int i = 0;i<3;i++){
        int start_x,start_y;
        cin >> start_x >> start_y;
        v.push_back({start_x-1,start_y-1});
    }
}
 
void bfs(){
    queue<info> q;
 
    for(int i = 0;i<v.size();i++){
        q.push({v[i].first,v[i].second,i});
        dt[v[i].first][v[i].second][i] = 0;
        time_[v[i].first][v[i].second][i] = 0;
    }
    while(!q.empty()){
        int cursize = q.size();
        for(int i = 0;i<cursize;i++){
            int x = q.front().x;
            int y = q.front().y;
            int data = q.front().data;
            q.pop();
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                    continue;
                }
                if(data == 0){
                    if(map[nx][ny] == '0' && dt[nx][ny][data] == -1){
                        dt[nx][ny][data] = dt[x][y][data] + 1;
                        q.push({nx,ny,data});
                        time_[nx][ny][data] = TIME;
                    }
                }
                else if(data == 1){
                    if(map[nx][ny] == '0' && dt[nx][ny][data] == -1){
                        dt[nx][ny][data] = dt[x][y][data] + 1;
                        q.push({nx,ny,data});
                        time_[nx][ny][data] = TIME;
                    }
                }
                else if(data == 2){
                    if(map[nx][ny] == '0' && dt[nx][ny][data] == -1){
                        dt[nx][ny][data] = dt[x][y][data] + 1;
                        q.push({nx,ny,data});
                        time_[nx][ny][data] = TIME;
                    }
                }
            }
 
 
 
        }
        TIME++;
    }
 
}
int main(void){
    init();
    bfs();
  
    int arrival_time = 0;
    int min_time = -1;
    vector<int> times;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dt[i][j][0] == -1 || dt[i][j][1] == -1 || dt[i][j][2] == -1){
                continue;
            }
                int arrival = dt[i][j][0] + dt[i][j][1] + dt[i][j][2];
                arrival_time = -1;
                arrival_time = max(time_[i][j][0]+1,time_[i][j][1] + 1);
                arrival_time = max(arrival_time,time_[i][j][2] + 1);
                times.push_back(arrival_time);
 
        }
    }
 
    if(times.size() == 0){
        cout << -1;
        return 0;
    }   
 
    
    sort(times.begin(),times.end());
    int cnt = 1;
    arrival_time = times[0];
    for(int i = 1;i<times.size();i++){
        if(times[i] == arrival_time){
            cnt++;
        }
    }
 
    cout << arrival_time << '\n';
    cout << cnt;
 
 
 
 
}
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
 
set<int> s;
set<int>::iterator iter;
vector<pair<int,int>> v;
int n,m;
char map[2003][2003];
int start_x,start_y = 0;
int end_x,end_y = 0;
bool valid = false;
int dt[2003][2003];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int NUMBER = 0;
bool visited[2003][2003];
 
void init(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            dt[i][j] = -1;
            if(map[i][j] == '.'){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(valid == false){
                        valid = true;
                        start_x = i;
                        start_y = j;
                    }
                    else{
                        end_x = i;
                        end_y = j;
                    }
                }   
           }
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
        if(x == end_x && y == end_y){
            return;
        }
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            if(dt[nx][ny] == -1 && map[nx][ny] == '.'){
                dt[nx][ny] = dt[x][y] + 1;
                q.push({nx,ny});
            }
        }
 
    }
}
 
void BFS(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    v.push_back({x,y});
 
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == start_x && y == start_y){
            return;
        }
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m ){
                continue;
            }
            iter = s.find(dt[nx][ny]);
            if(dt[nx][ny] == dt[x][y] - 1){
                q.push({nx,ny});
                v.push_back({nx,ny});
            }
        }
    }
}
int main(void){
    s.clear();
    init();
    int max = -1;
    bfs(start_x,start_y);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
           if(dt[i][j] != -1 && map[i][j] == '.'){
               if(dt[i][j] > max){
                   max = dt[i][j];
               }
           }
        }
    }
    NUMBER = max; 
    BFS(end_x,end_y);
    for(int i = 0;i<v.size();i++){
        dt[v[i].first][v[i].second] = -10;
    }
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(map[i][j] == '.' && dt[i][j] != -10){
                map[i][j] = '@';
            }
            cout << map[i][j];
        }
        cout << '\n';
    }
 
 
}
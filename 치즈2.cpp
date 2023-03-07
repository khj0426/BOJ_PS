#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> v;
int n,m;
bool visited[101][101];
char map[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0}; 

void input(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
}

void init(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            visited[i][j] = false;
        }
    }

}


void notMelted(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int cnt = 0;
            if(visited[i][j] == true && map[i][j] == '3'){
                for(int k = 0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                        continue;
                    }
                    if(map[nx][ny] == '0' && visited[nx][ny] == true){
                        cnt++;
                    }

                }

                if(cnt < 2){
                    map[i][j] = '1';
                }
                else{
                    v.push_back({i,j});
                }
             
            }
           
        }
    }

    for(int i = 0;i<v.size();i++){
        int x = v[i].first;
        int y = v[i].second;
        map[x][y] = '0';
    }
}

void Solve(){
    init();
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >=n || ny >= m){
                continue;
            }
            if(map[nx][ny] == '1' && !visited[nx][ny]){
                map[nx][ny] = '3';
                visited[nx][ny] = true;
            }
            else if(map[nx][ny] == '0' && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    notMelted();

}


bool checkisEnd(){
    bool isend = true;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(map[i][j] == '1'){
                return false;
            }
        }
    }
    return true;
}

int main(void){
    input();
    int timer = 0;
    while(1){
        if(checkisEnd()){
            break;
        }
        Solve();
        timer++;

    }
    cout << timer;
}


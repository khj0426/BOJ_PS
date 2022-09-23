#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int n,m,k;
int dt[1001][1001][11];
char map[1001][1001];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 
struct infomation{
    int x;
    int y;
    int data;
};
 
typedef struct infomation info;
 
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
void init(){
    cin >> n >> m >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            for(int q = 0;q<=k;q++){
                dt[i][j][q] = -1;
            }
        }
    }
}
 
void bfs(int x,int y){
    queue<info> q;
    q.push({x,y,0});
    dt[x][y][0] = 0;
 
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int data = q.front().data;
        if(x == n-1 && y == m-1){
            return;
        }
 
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            if(data == 0){
                if(map[nx][ny] == '0' && dt[nx][ny][0] == -1){
                    dt[nx][ny][0] = dt[x][y][0] + 1;
                    q.push({nx,ny,0});
                }
                else if(map[nx][ny] == '1' && dt[nx][ny][1] == -1){
                    dt[nx][ny][1] = dt[x][y][0] + 1;
                    q.push({nx,ny,1});
                }
            }
            else if(data != 0){
                    if(map[nx][ny] == '0' && dt[nx][ny][data] == -1){
                        dt[nx][ny][data] = dt[x][y][data] + 1;
                        q.push({nx,ny,data});
                    }
                    else if(map[nx][ny] == '1' && dt[nx][ny][data+1] == -1 && data + 1 <= k){
                        dt[nx][ny][data+1] = dt[x][y][data] + 1;
                        q.push({nx,ny,data+1});
                    }
            }
        }
    }
}
 
int main(void){
    init();
    bfs(0,0);
 
    int ans = 987654321;
    for(int i = 0;i<=k;i++){
        if(dt[n-1][m-1][i] != -1){
            ans = min(ans,dt[n-1][m-1][i] + 1);
        }
 
    }
    if(ans == 987654321){
        cout << -1;
        return 0;
    }
    cout << ans;
}
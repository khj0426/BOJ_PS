#include <iostream>
#include <vector>
#define MAX 51
using namespace std;
int w,h;
bool visited[MAX][MAX];
int map[MAX][MAX];
int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,-1,1,1,1,-1,-1};
void init(){
    for(int i = 0;i<=MAX;i++){
        for(int j = 0;j<=MAX;j++){
            visited[i][j] = false;
            map[i][j] = 0;
        }
    }
}

void dfs(int x,int y){
    visited[x][y] = true;
 
    for(int i = 0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= h || ny >= w){
            continue;
        }
        if(map[nx][ny] == 1 && visited[nx][ny] == false){
            dfs(nx,ny);
        }
    }
}
 
int main(void){
    while(1){  
        init();
        cin >> w >> h; 
        if(w == 0 && h == 0){
            break;
        }
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                cin >> map[i][j];
            }
        }
 
        int cnt = 0;
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(map[i][j] == 1 && visited[i][j] == false){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}

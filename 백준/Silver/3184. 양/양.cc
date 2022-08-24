#include <iostream>
using namespace std;
 
int r,c;
bool visited[251][251];
char map[251][251];
 
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 
int total_sheep = 0;
int total_wolf = 0;
int current_wolf = 0;
int current_sheep = 0;
 
void dfs(int x,int y){
 
    if(map[x][y] == 'o'){
        current_sheep++;
    }
    else if(map[x][y] == 'v'){
        current_wolf++;
    }
 
    visited[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= r || ny >= c){
            continue;
        }
        char c = map[nx][ny];
 
        if(visited[nx][ny] == false && c != '#'){
            dfs(nx,ny);
        }
    }
 
}
 
int main(void){
    cin >> r >> c;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
        }
    }
 
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            current_wolf = 0;
            current_sheep = 0;
            if(visited[i][j] == false && map[i][j] != '#'){
                dfs(i,j);
                if(current_sheep > current_wolf){
                    total_sheep += current_sheep;
                }
                else{
                    total_wolf += current_wolf;
                }
            }
        }
    }
    cout << total_sheep << ' ' << total_wolf;
}

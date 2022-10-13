#include <iostream>
#include <string>
using namespace std;
 
bool visited[51][51];
char map[51][51];
int n,m;
bool is_find = false;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 int start_x = 0;
 int start_y = 0;
 
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
 
void dfs(int x,int y,int depth){
    if(depth >= 4 && x == start_x && y == start_y){
        is_find = true;
        return;
    }
 
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            continue;
        }
        if(map[nx][ny] == map[x][y] && visited[nx][ny] == false){
            visited[nx][ny] = true;
            dfs(nx,ny,depth+1);
            visited[nx][ny] = false;
        }
    }
}
 
int main(void){
    input();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            init();
            start_x = i;
            start_y = j;
 
            dfs(i,j,1);
            if(is_find == true){
                cout << "Yes";
                return 0;
            }
        }
    }
 
    cout << "No";
 
}
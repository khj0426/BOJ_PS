#include <iostream>
#include <string>
using namespace std;
 
bool visited[1001][1001];
int n,m;
char map[1001][1001];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool is_percolate = false;
 
void init(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            visited[i][j] = false;
        }
    }
}
 
void dfs(int x,int y){
 
    if(visited[x][y]){
        return;
    }
    if(x == n-1 && map[x][y] == '0'){
        is_percolate = true;
 
    }
     visited[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            continue;
        }
        if(visited[nx][ny] == false && map[nx][ny] == '0'){
 
            dfs(nx,ny);
        }
    }
}
int main(void){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
 
        }
    }
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(map[i][j] == '0' && i == 0){
 
                init();
                dfs(i,j);
                if(is_percolate == true){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
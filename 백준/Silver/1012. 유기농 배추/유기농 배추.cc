#include <iostream>
#include <vector>
#define MAX 51
using namespace std;
bool visited[MAX][MAX];
int board[MAX][MAX];
int m,n; //m은 가로 n은 세로
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt = 0;
 
void init(){
    for(int i = 0;i<MAX;i++){
        for(int j = 0;j<MAX;j++){
            board[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
 
void dfs(int x,int y){
    visited[x][y] = true;
 
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n|| ny >= m){
            continue;
        }
        if(visited[nx][ny] == false && board[nx][ny] == 1){
            dfs(nx,ny);
        }
    }
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        init();
        int num;
        cin >> m >> n >> num;
 
 
        for(int i = 0;i<num;i++){
            int x,y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(visited[i][j] == false && board[i][j] == 1){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        cnt = 0;
    }
}
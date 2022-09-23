#include <iostream>
#include <queue>
using namespace std;
 
int n;
char map[51][51];
int dt[51][51][2525];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int num_of_black = 0;
 
struct infomation{
    int x;
    int y;
    int num_of_break;
};
 
typedef struct infomation info;
 
void init(){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == '0'){
                num_of_black++;
            }
        }
    }
 
    for(int i = 0;i<=num_of_black;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                dt[j][k][i] = -1;
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
        int num_of_break = q.front().num_of_break;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n){
                continue;
            }
            if(num_of_break == 0){
                if(map[nx][ny] == '1' && dt[nx][ny][0] == -1){
                    dt[nx][ny][0] = dt[x][y][0] + 1;
                    q.push({nx,ny,0});
                }
 
                //처음으로 바뀌는 경우
                else if(map[nx][ny] == '0' && dt[nx][ny][1] == -1){
                    dt[nx][ny][1] = dt[x][y][0] + 1;
                    q.push({nx,ny,1});
                }
            }
 
            //바꾸는 경우의 횟수 제한 X
            else if(num_of_break != 0){
                if(map[nx][ny] == '1' && dt[nx][ny][num_of_break] == -1){
                    dt[nx][ny][num_of_break] = dt[x][y][num_of_break] + 1;
                    q.push({nx,ny,num_of_break});
                }
                else if(map[nx][ny] == '0' && dt[nx][ny][num_of_break + 1] == -1){
                    dt[nx][ny][num_of_break+1] = dt[x][y][num_of_break] + 1;
                    q.push({nx,ny,num_of_break+1});
                }
            }
        }
    }
}
 
int main(void){
    init();
    bfs(0,0);
    int ans = 987654321;
    for(int i = 0;i<=num_of_black;i++){
        if(dt[n-1][n-1][i] != -1){
            cout << i;
            return 0;
        }
    }
 
}
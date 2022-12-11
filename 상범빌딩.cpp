#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
 
struct infomation{
    int z;
    int x;
    int y;
    int data;
};
 
typedef struct infomation info;
int l,r,c;
int startz,startx,starty;
int endz,endx,endy;
char map[31][31][31];
int visited[31][31][31];
int dz[6] = {0,0,0,0,1,-1};
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
 
bool init(){
    cin >> l >> r >> c;
    if(l == 0 && r == 0 && c == 0){
        return false;
    }
    for(int i = 0;i<l;i++){
        for(int p = 0;p<r;p++){
            for(int q = 0;q<c;q++){
                cin >> map[i][p][q];
                visited[i][p][q] = -1;
                if(map[i][p][q] == 'S'){
                    startz = i;
                    startx = p;
                    starty = q;
                }
                else if(map[i][p][q] == 'E'){
                    endz = i;
                    endx = p;
                    endy = q;
                }
            }
        }
    }
    return true;
}
 
void bfs(int startZ,int startX,int startY){
    queue<info> q;
    visited[startZ][startX][startY] = 0;
    info first = {startZ,startX,startY,visited[startZ][startX][startY]};
    q.push(first);
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int data = q.front().data;
        q.pop();
        if(z == endz && x == endx && y == endy){
            return;
        }
        for(int i = 0;i<6;i++){
            int nz = dz[i] + z;
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nz < 0 || nz > l || nx < 0 || nx > r || ny < 0 || ny > c){
                continue;
            }
            if(map[nz][nx][ny] != '#'){
                if(visited[nz][nx][ny] == -1){
                    visited[nz][nx][ny] = data + 1;
                    info datas = {nz,nx,ny,visited[nz][nx][ny]};
                    q.push(datas);
                }
            }
        }
    }
}
 
int main(void){
    while(init() != false){
        bfs(startz,startx,starty);
        if(visited[endz][endx][endy] != -1){
            cout << "Escaped in " << visited[endz][endx][endy] <<  " minute(s)." << '\n';
        }
        else{
            cout << "Trapped!" << '\n';
        }
    }
}


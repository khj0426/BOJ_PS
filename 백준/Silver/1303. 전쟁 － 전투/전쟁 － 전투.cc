#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n,m;
int B = 1;
int W = 1;
 
vector<int> b;
vector<int> w;
void init(){
    for(int i = 0;i<MAX;i++){
        for(int j = 0;j<MAX;j++){
            visited[i][j] = false;
        }
    }
}
void dfs_W(int x,int y){
 
    visited[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            continue;
        }
        if(visited[nx][ny] == false && map[nx][ny] == 'W'){
            W++;
            dfs_W(nx,ny);
        }
    }
}
 
void dfs_B(int x,int y){
 
    visited[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            continue;
        }
        if(visited[nx][ny] == false && map[nx][ny] == 'B'){
            B++;
            dfs_B(nx,ny);
        }
    }
}
 
int main(void){
    cin >> m >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] == false && map[i][j] == 'W'){
                dfs_W(i,j);
                w.push_back((W)*(W));
                W = 1;
 
            }
        }
    }
    init();
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] == false && map[i][j] == 'B'){
                dfs_B(i,j);
                b.push_back(B*B);
                B = 1;
            }
        }
    }
 
 
    B = 0;
    W = 0;
    for(int i = 0;i<b.size();i++){
        B = B + b[i];
    }
 
    for(int i = 0;i<w.size();i++){
        W = W + w[i];
    }
    cout << W << ' ' << B;
}
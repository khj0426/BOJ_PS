#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int r,c;
 
bool visited[MAX][MAX];
int map[MAX][MAX];
int depth = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<int> v;
 
void dfs(int x,int y){
    depth++;
    visited[x][y] = true;
 
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > r || ny > c){
            continue;
        }
        if(map[nx][ny] == 1 && visited[nx][ny] == false){
            dfs(nx,ny);
        }
    }
}
int main(void){
    cin >> r >> c;
    int k;
    cin >> k;
    for(int i = 0;i<k;i++){
        int a,b;
        cin >> a >> b;
        map[a][b] = 1;
    }
 
    for(int i = 1;i<=r;i++){
        for(int j = 1;j<=c;j++){
            if(visited[i][j] == false && map[i][j] == 1){
                dfs(i,j);
                v.push_back(depth);
                depth = 0;
            }
        }
    }
 
    sort(v.begin(),v.end());
    cout << v[v.size()-1];
}
 

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAX 26
using namespace std;
vector<int> v;
int map[MAX][MAX];
bool visited[MAX][MAX];
int n;
int dx[4] = {1,0,-1,0}; //오른쪽,밑,왼쪽,위
int dy[4] = {0,-1,0,1}; //오른쪽, 밑 ,왼쪽 ,위
int cnt = 0;
int depth = 0;
void dfs(int x,int y){
    if(visited[x][y]){
        return;
    }
    visited[x][y] = true;
 
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
         if(nx < 0 || ny < 0 || nx >= n || ny >= n){
                continue;
            }
 
        if(map[nx][ny] == 1 && visited[nx][ny] == false){ 
            dfs(nx,ny);
            depth++;
        }
    }
}
int main(void){
    cin >> n;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%1d",&map[i][j]);
        }
    }
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(map[i][j] == 1 && visited[i][j] == false){
                dfs(i,j);
                cnt++;
                v.push_back(depth);
                depth = 0;
 
            }
        }
    }
    cout << cnt << '\n';
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        cout << v[i]+1 << '\n';
    }
}
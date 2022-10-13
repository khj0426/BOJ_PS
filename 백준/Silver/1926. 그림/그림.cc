#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 600
using namespace std;
 
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
 
bool visited[MAX][MAX];
int map[MAX][MAX];
int n,m;
int cnt = 0;
int SIZE = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
 int depth = 1;
vector<int> v;
 
void dfs(int x,int y){
    visited[x][y] = true;
 
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            continue;
        }
        if(visited[nx][ny] == false && map[nx][ny] == 1){
            visited[nx][ny] = true;
            depth++;
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
            if(visited[i][j] == false && map[i][j] == 1){
                cnt++;
                dfs(i,j);
                v.push_back(depth);
 
                depth = 1;
 
            }
        }
    }
 
    sort(v.begin(),v.end());
    cout << cnt << '\n';
    if(v.size() >= 1){
    cout << v[v.size()-1];
        }
    else{
cout << '0';
    }
}
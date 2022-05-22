#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 110
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
 
vector<int> v;
bool visited[MAX][MAX];
int map[MAX][MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n;
int Count = 0;
int height = 0;
int ans = 0;
 
void init(){
for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        visited[i][j] = false;
    }
}
}
 
void dfs(int x,int y){
    visited[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n){
            continue;
        }
        if(visited[nx][ny] == false && map[nx][ny] > height){
            dfs(nx,ny);
        }
    }
}
 
int main(void){
    cin >> n;
    int max_height = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] > max_height){
                max_height = map[i][j];
            }
        }
    }
 
    while(height <= max_height){
        init();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(visited[i][j] == false && map[i][j] > height){
                    dfs(i,j);
                    Count++;
                }
 
            }
        }
 
            ans = max(Count,ans);
            Count = 0;
            height++;
    }
 
    cout << ans;
}
 
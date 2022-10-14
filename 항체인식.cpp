#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool init_check = false;
bool not_ans_flag = false;
int n,m;
int arr[31][31];
int after_arr[31][31];
bool visited[31][31];
vector<pair<int,int>> ans;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 
void input(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> after_arr[i][j];
        }
    }
}
 
void bfs(int x,int y,int nextvalue){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            if(visited[nx][ny] == false && arr[nx][ny] == arr[x][y]){
                visited[nx][ny] = true;
                q.push({nx,ny});
 
            }
        }
    }
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] == true){
                arr[i][j] = nextvalue;
            }
        }
    }
}
 
 
 
void solve(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j] != after_arr[i][j] && init_check == false){
                init_check = true;
                bfs(i,j,after_arr[i][j]);
            }
            else if(arr[i][j] != after_arr[i][j] && init_check == true){
                not_ans_flag = true;
            }
        }
    }
     
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] == true && arr[i][j] != after_arr[i][j]){
                not_ans_flag = true;
            }
        }
    }
}
 
int main(void){
    input();
    solve();
    if(not_ans_flag == true){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
 
}
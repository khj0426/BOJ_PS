#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
 
bool visited[51][51];
int n;
vector<pair<int,int>> position;
int arr[51][51];
int L,R;
int init_time = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 
int out_range(int x){
    if(x < 0 || x >= n){
        return -1;  //Outof range
    }
    return 1; //in_range
}
 
void input(){
    cin >> n;
    cin >> L >> R;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}
 
int bfs(int x,int y){
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    int sum = 0;
    sum += arr[x][y];
    cnt++;
    position.push_back({x,y});
 
    visited[x][y] = 1;
 
    while(!q.empty()){
        int firstx = q.front().first;
        int firsty = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = firstx + dx[i];
            int ny = firsty + dy[i];
            if(out_range(nx) == 1 && out_range(ny) == 1){
                if(abs(arr[firstx][firsty] - arr[nx][ny]) >= L && abs(arr[firstx][firsty]-arr[nx][ny]) <= R){
                    if(visited[nx][ny] == false){
                        visited[nx][ny] = true;
                        cnt++;
                        q.push({nx,ny});
                        sum += arr[nx][ny];
                        position.push_back({nx,ny});
                    }
                } 
            }
        }
    }
    return sum/cnt;
}
 
int check_is_open(){
    int x = 0;
    int y = 0;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            visited[i][j] = false;
        }
    }
    bool valid = false;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            position.clear();
            if(visited[i][j] == false){
                int value_ = bfs(i,j);
                
                if(position.size() != 1){
                    valid = true;
                    for(int k = 0;k<position.size();k++){
                    int nextx = position[k].first;
                    int nexty = position[k].second;
                    arr[nextx][nexty] = value_;
                    }
                }
 
            }
        }
    }
    if(valid == false){
        return -1;
    }
    else{
        return 1;
    }
 
 
}
 
int main(void){
    input();
    while(1){
        if(check_is_open() == -1){
            break;
        }
        else{
            init_time++;
        }
    }
    cout << init_time;
    
 
}
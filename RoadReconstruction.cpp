#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 987654321
//Road Reconstruction
using namespace std;
 
int n,m;
 
//0은 도로가 이미 존재하는 경우
//1은 도로가 없고 1의 비용으로 건설 가능
//2는 도로가 없고 2의 비용으로 건설 가능
//-1은 도로 건설 불가
 
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int arr[1001][1001]; //node
int dt[1001][1001];//cost
 
typedef pair<int,pair<int,int>> p;
void init(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
            dt[i][j] = MAX;
        }
    }
}
 
void solve(int x,int y,int data){
    priority_queue<p,vector<p>,greater<p>> q;
    if(data == 1){
        dt[x][y] = 1;
    }
    else if(data == 0){
        dt[x][y] = 0;
    }
    else if(data == 2){
        dt[x][y] = 2;
    }
    q.push({dt[x][y],{x,y}});
 
    while(!q.empty()){
        int data = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        if(x == n-1 && y == m-1){
            return;
        }
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            if(arr[nx][ny] == 1){
                //비용 1로 도로 건설 가능
                if(data + 1 < dt[nx][ny]){
                    dt[nx][ny] = data + 1;
                    q.push({dt[nx][ny],{nx,ny}});
                    arr[nx][ny] = 3;
                }
            }
            else if(arr[nx][ny] == 2){
                if(data + 2 < dt[nx][ny]){
                    dt[nx][ny] = data + 2;
                    q.push({dt[nx][ny],{nx,ny}});
                    arr[nx][ny] = 3;
                }
            }
            else if(arr[nx][ny] == 0){
                if(data < dt[nx][ny]){
                    dt[nx][ny] = data;
                    arr[nx][ny] = 3;
                    q.push({dt[nx][ny],{nx,ny}});
                }
            }
        }
    }
}
int main(void){
    init();
    solve(0,0,arr[0][0]);
    if(dt[n-1][m-1] == MAX){
        cout << -1;
    }
    else{
        cout << dt[n-1][m-1];
    }
}
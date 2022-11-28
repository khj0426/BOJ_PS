#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 987654321
 
using namespace std;
struct infomation{
    int x;
    int y;
    int data;
};
 
typedef struct infomation info;
 

struct compare{
    bool operator()(info a,info b){
        return a.data > b.data;
    }
};
 
int t;
int n;
int dt[126][126];
bool visited[126][126];
int arr[126][126];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 
void input(int size){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            dt[i][j] = MAX;
            visited[i][j] = 0;
            cin >> arr[i][j];
        }
    }
}
 
void solve(int start_x,int start_y){
    priority_queue<info,vector<info>,compare> q;
    q.push({start_x,start_y,arr[start_x][start_y]});
    dt[start_x][start_y] = arr[start_x][start_y];
 
    while(!q.empty()){
        int x = q.top().x;
        int y = q.top().y;
        int data = q.top().data;
        if(x == n-1 && y == n-1){
            return;
        }
        q.pop();
        if(visited[x][y] == 1){
            continue;
        }
        visited[x][y] = 1;
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(dt[nx][ny] > data + arr[nx][ny]){
                dt[nx][ny] = data + arr[nx][ny];
                q.push({nx,ny,dt[nx][ny]});
            }
        }
    }
}
 
int main(void){
    int first = 1;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        input(n);
        solve(0,0);
        cout << "Problem" << ' ' << first << ':' << ' ' <<  dt[n-1][n-1] << '\n';
        first++;
    }
}
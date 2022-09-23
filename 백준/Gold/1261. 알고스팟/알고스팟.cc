#include <iostream>
#include <queue>
#define MAX 987654321
#include <algorithm>
#include <vector>
using namespace std;
 
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
char map[101][101];
vector<int> v;
int dt[101][101];
 
struct infomation{
    int data;
    int x;
    int y;
};
 
typedef struct infomation info;
 
struct compare{
    bool operator()(info A,info B){
        return A.data > B.data;
    }
};
 
typedef struct infomation info;
 
void init(){
    cin >> m >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            dt[i][j] = MAX;
            cin >> map[i][j];
        }
    }
}
 
int solve(int x,int y){
    priority_queue<info,vector<info>,compare> q;
    dt[x][y] = 0;
    q.push({dt[x][y],x,y});
 
    while(!q.empty()){
        int cur = q.size();
        for(int i = 0;i<cur;i++){
            int x = q.top().x;
            int y = q.top().y;
            int data = q.top().data;
            if(x == n-1 && y == m-1){
                return data;
            }
            q.pop();
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                    continue;
                }
                if(map[nx][ny] == '0'){
                    if(data < dt[nx][ny]){
                        dt[nx][ny] = data;
                        info temp;
                        temp.x = nx;
                        temp.y = ny;
                        temp.data = dt[nx][ny];
                        q.push(temp);
                    }
                }
                else if(map[nx][ny] == '1'){
                    if(data + 1 < dt[nx][ny]){
                        dt[nx][ny] = dt[x][y] + 1;
                        info temp;
                        temp.x = nx;
                        temp.y = ny;
                        temp.data = dt[nx][ny];
                        q.push(temp);
                    }
 
                }
            }
        }
 
 
    }
}
 
int main(void){
    init();
    cout << solve(0,0);
 
}
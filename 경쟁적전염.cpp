#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
 //백준 경쟁적 전염

int n,k;
int map[201][201];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

struct infomation{
    int x;
    int y;
    int data;
};
 
typedef struct infomation info;
 
bool compare(info a,info b){
    return a.data < b.data;
}
 
void init(){
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> map[i][j];
        }
 
    }
}

int check_is_fill(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(map[i][j] == 0){
                return -1;
            }
        }
    }
    return 1;
}
 
void bfs(int x,int y,int query,int last_x,int last_y){
    int time = 0;
    queue<pair<int,int>> q;
    vector<info> v;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(map[i][j] != 0){
                v.push_back({i,j,map[i][j]});
            }
        }
    }
 
    sort(v.begin(),v.end(),compare);
    for(int i = 0;i<v.size();i++){
        q.push({v[i].x,v[i].y});
    }
 
    while(!q.empty()){
       
        if(time == query){
            return;
        }

        int cursize = q.size();
        for(int i = 0;i<cursize;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
           for(int j = 0;j<4;j++){
               int nx = x + dx[j];
               int ny = y + dy[j];
               if(nx < 1 || ny < 1 || nx > n || ny > n){
                   continue;
               }
               if(map[nx][ny] == 0){
                   map[nx][ny] = map[x][y];
                   q.push({nx,ny});
               }
           }
        }

        time++;
 
    }
} 
 
int main(void){
    init();
    int time,x,y;
    cin >> time >> x >> y;
    bfs(1,1,time,x,y);
    cout << map[x][y];
 
 
}
/*다른 방법 -> 3차원 배열로 관리 */

//검을 안먹었을 떄는 dt[x][y][0]에서 탐색을 하고
//검을 먹었을 떄는 dt[x][y][1]에서 탐색을 이어가는 방식

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int time_ = 0;
int n,m,t;
int dt[103][103][2];
int map[103][103];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int draw_x,draw_y;


struct info{
    int x;
    int y;
    int data;
};

typedef struct info ifo;

void init(){
    cin >> n >> m >> t;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            dt[i][j][0] = -1;
            dt[i][j][1] = -1;
            if(map[i][j] == 2){
                draw_x = i;
                draw_y = j;
            }
        }
    }
}

void bfs(int x,int y){
    queue<ifo> q;
    q.push({x,y,0});
    dt[x][y][0] = 0;

    while(!q.empty()){
        int cursize = q.size();
        for(int i = 0;i<cursize;i++){
            int x = q.front().x;
            int y = q.front().y;
            int data = q.front().data;
            q.pop();
            if(x == n-1 && y == m-1){
                return;
            } 
            
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                    continue;
                }
                if(data == 0){
                    if(map[nx][ny] == 2){
                        if(dt[nx][ny][1] == -1){
                            dt[nx][ny][1] = 0;
                            q.push({nx,ny,1});
                        }
                    }
                    else if(map[nx][ny] == 0){
                        if(dt[nx][ny][0] == -1){
                            dt[nx][ny][0] = dt[x][y][0] + 1;
                            q.push({nx,ny,0});
                        }
                    }
                }
                else if(data == 1){
                    if(dt[nx][ny][1] == -1){
                        dt[nx][ny][1] = dt[x][y][1] + 1;
                        q.push({nx,ny,1});
                    }
                }
            }

        }
 
        time_++;
    }
}

int main(void){
    init();
    bfs(0,0);
    if(dt[n-1][m-1][0] == -1 && dt[n-1][m-1][1] == -1){
        cout << "Fail";
        return 0;
    }
    else{
        if(time_ <= t){
            cout << time_;
        }
        else{
            cout << "Fail";
        }
        
    }
    
    
    
}

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct infomation{
    int first;
    int second;
    int num;
};

typedef struct infomation info;

vector<info> v;
bool visited[301][301];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n,m;
int map[301][301];
void init(){
    v.clear();
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            visited[i][j] = false;
            
            if(map[i][j] != 0){
                int cnt = 0;
                for(int k = 0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                        continue;
                    }
                    if(map[nx][ny] == 0){
                        cnt++;
                    }
                }
                v.push_back({i,j,cnt});
            }
            
          
            
        }
    }
}



void bfs(int x,int y){
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
            if(map[nx][ny] != 0 && visited[nx][ny] == false){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
}



int decrease(){
    bool valid = false;
    if(v.size() == 0){
        return 1;
    }
     for(int i = 0;i<v.size();i++){
         if(visited[v[i].first][v[i].second] == false){
             return 1;
         }
         if(map[v[i].first][v[i].second] - v[i].num < 0){
             map[v[i].first][v[i].second] = 0;
         }
         else{
             map[v[i].first][v[i].second] -= v[i].num; 
         }
         
     }
    return -1;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    
   while(1){
       init();
       bfs(v[0].first,v[0].second);
       if(decrease() == 1){
           break;
       }
       else{
           cnt++;
           continue;
       }
   }
    if(v.size() == 0){
        cnt = 0;
    }
    cout << cnt;

}

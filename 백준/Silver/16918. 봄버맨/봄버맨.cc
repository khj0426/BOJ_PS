#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
 
int r,c,n;
char map[210][210];
queue<pair<int,int>> boom;
int first_time = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 
void input(){
    cin >> r >> c >> n;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j] == 'O'){
                boom.push({i,j}); //폭탄 설치;
            }
        }
    }
}
 
void setting(){ //모든 칸에 폭탄 설치
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
                map[i][j] = 'O';
        }
    }
}
 
//폭탄이 폭파되고 3초 뒤 폭팔 할 폭탄 설치
void install(){
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(map[i][j] == 'O'){
                boom.push({i,j});
            }
        }
    }
}
 
 
void bfs(int time){
 
    while(time < n){
    if(time == n){
        return;
    }    
    setting();
    time++;
    if(time == n){
    	return;
    }
 
    int boom_size = boom.size();
    for(int i = 0;i<boom_size;i++){
        int x = boom.front().first;
        int y = boom.front().second;
        for(int j = 0;j<4;j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c){
                continue;
            }
            map[nx][ny] = '.';
        }
        map[x][y] = '.';
        boom.pop();
    }
 
 
    install();
    time++;
    if(time == n){
    	return;
    }
    }
 
}
 
int main(void){
    input();
    if(n == 1){
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                cout << map[i][j];
            }
            cout << '\n';
        }
        return 0;
    }
    setting();
    first_time++;
    
 
    bfs(first_time);
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
 
 
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
 
struct infomation{
	int x;
	int y;
	int data;
};
 
typedef struct infomation info;
 
int min(int a,int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int dt[1001][1001][2];
 
char map[1001][1001];
 
void init(){
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> map[i][j];
			dt[i][j][0] = -1;
			dt[i][j][1] = -1;
		}
	}
}
 
void bfs(int x,int y){
	queue<info> q;
	q.push({x,y,0});
	dt[x][y][0] = 0;
 
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int data = q.front().data;
		if(x == n-1 && y == m-1){
			return;
		}
		q.pop();
		for(int i = 0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m ){
				continue;
			}
			if(data == 0){
				if(map[nx][ny] == '0' && dt[nx][ny][0] == -1){
					q.push({nx,ny,0});
					dt[nx][ny][0] = dt[x][y][0] + 1;
 
				}
				else if(map[nx][ny] == '1' && dt[nx][ny][1] == -1){
					q.push({nx,ny,1});
					dt[nx][ny][1] = dt[x][y][0] + 1;
 
				}
			}
			else if(data == 1){
					if(map[nx][ny] == '0' && dt[nx][ny][1] == -1){
						q.push({nx,ny,1});
						dt[nx][ny][1] = dt[x][y][1] + 1;
					}
 
 
			}
		}
	}
 
}
 
int main(void){
	init();
	bfs(0,0);
 
	if(dt[n-1][m-1][0] == -1 && dt[n-1][m-1][1] == -1){
		cout << -1;
	}
	else if(dt[n-1][m-1][0] == -1 && dt[n-1][m-1][1] != -1){
		cout << dt[n-1][m-1][1] + 1;
	}
	else if(dt[n-1][m-1][0] != -1 && dt[n-1][m-1][1] == -1){
		cout << dt[n-1][m-1][0] + 1;
	}
	else{
		cout << min(dt[n-1][m-1][0] + 1,dt[n-1][m-1][1] + 1);
	}
}
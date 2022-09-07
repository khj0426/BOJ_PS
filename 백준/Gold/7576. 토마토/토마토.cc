#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int m,n;
int map[1001][1001];
 
int day = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<pair<int,int>> v;
 
void init(){
	cin >> m >> n;
	//m은 가로 , n은 세 
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> map[i][j];
			if(map[i][j] == 1){
				v.push_back({i,j});
			}
		}
	}
 
}
 
int check(){
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(map[i][j] == 0){
				return -1;
			}
		}
	}
	return 1;
}
 
void bfs(){
	queue<pair<int,int>> q;
	for(int i = 0;i<v.size();i++){
		q.push({v[i].first,v[i].second});
 
	}
	while(!q.empty()){
 
		if(check() == 1){
			return;
		}
 		int cur = q.size();
		for(int i = 0;i<cur;i++){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
 
			for(int j = 0;j<4;j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m){
					continue;
				}
				if(map[nx][ny] == 0){
					map[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
		}
 
		++day;
	}
 
 
 
 
} 
 
 
int main(void){
	init();
 
	bfs();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(map[i][j] == 0){
				cout << -1;
				return 0;
			}
		}
	}
	cout << day;
}
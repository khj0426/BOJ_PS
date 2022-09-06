#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;
 
int dt[51][51];
int r,c;
char arr[51][51];
vector<pair<int,int>> water;
int start_x = 0;
int start_y = 0;
int end_x = 0;
int end_y = 0;
 
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 int ans = 0;
int min(int a,int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}
 
void init(){
	cin >> r >> c;
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			cin >>arr[i][j];
			dt[i][j] = -1;
			if(arr[i][j] == '*'){
				water.push_back({i,j});
			}
			if(arr[i][j] == 'S'){
				start_x = i;
				start_y = j;
			}
			else if(arr[i][j] == 'D'){
				end_x = i;
				end_y = j;
			}
		}
	}
}
void bfs(int x,int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	dt[x][y] = 0;
	while(!q.empty()){
 
        vector<pair<int,int>> next_water;
			for(int j = 0;j<water.size();j++){
				int water_x = water[j].first;
				int water_y = water[j].second;
                for(int k = 0;k<4;k++){
                    int water_nx = water_x + dx[k];
				    int water_ny = water_y + dy[k];
                    if(water_nx < 0 || water_ny < 0 || water_nx >= r || water_ny >= c){
					continue;
			    	}
                    if(arr[water_nx][water_ny] == '.'){
					arr[water_nx][water_ny] = '*';
					next_water.push_back({water_nx,water_ny});
				}
                }
 
			}
 
        water.clear();
        water = next_water;
        
        for(int i = 0;i<q.size();i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || ny < 0 || nx >= r || ny >= c){
                    continue;
                }
                if(dt[nx][ny] == -1 && arr[nx][ny] != 'X' && arr[nx][ny] != '*'){
                    dt[nx][ny] = dt[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
 
 
 
	}
}
int main(void){
	init();
	bfs(start_x,start_y);
 
    if(dt[end_x][end_y] == -1){
        cout << "KAKTUS";
    }
    else{
        cout << dt[end_x][end_y];
    }
 
 
}
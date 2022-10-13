#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
vector<pair<int,int>> empty_space;
int n,m;
char map[10][10];
char copy_map[10][10];
bool visited[11][11];
int dx[4] = {0,0,-1,1,};
int dy[4] = {1,-1,0,0};
int ans = 0;
 
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
void init(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == '0'){
                empty_space.push_back({i,j});
 
            }
        }
    }
}
void bfs(){
    queue<pair<int,int>> q;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(copy_map[i][j] == '2'){
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }
 
    while(!q.empty()){
        int first_ = q.front().first;
        int second_ = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = first_ + dx[i];
            int ny = second_ + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            if(copy_map[nx][ny] == '0' && visited[nx][ny] == false){
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
}
 
void permutation(){
 
 
    vector<int> combinate;
    for(int i = 0;i<3;i++){
        combinate.push_back(1);
    }
    for(int i = 0;i<empty_space.size()-3;i++){
        combinate.push_back(0);
    }
    sort(combinate.begin(),combinate.end());
 
    do{
        for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            copy_map[i][j] = map[i][j];
            visited[i][j] = false;
        }
    }
        vector<pair<int,int>> temp_vector;
        for(int i = 0;i<empty_space.size();i++){
            if(combinate[i] == 1){
                int first_element = empty_space[i].first;
                int second_element = empty_space[i].second;
                temp_vector.push_back({first_element,second_element});
            }
        }
        for(int i = 0;i<temp_vector.size();i++){
            copy_map[temp_vector[i].first][temp_vector[i].second] = '1';
        }
        bfs();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(copy_map[i][j] == '0' && visited[i][j] == false){
                    cnt++;
                }
            }
        }
        ans = max(ans,cnt);
 
 
    }while(next_permutation(combinate.begin(),combinate.end()));
}
 
 
int main(void){
    init();
    permutation();
    cout << ans;
}
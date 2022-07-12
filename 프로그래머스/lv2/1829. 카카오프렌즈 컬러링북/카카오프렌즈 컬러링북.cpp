#include <iostream>
#include <vector>

using namespace std;

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int N,M;
int map[101][101];
bool visited[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int depth = 0;

void init(){
    for(int i = 0;i<=100;i++){
        for(int j = 0;j<=100;j++){
            visited[i][j] = false;
            map[i][j] = 0;
        }
    }
}

void dfs(int x,int y){

    
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N){
            continue;
        }
        if(map[nx][ny] == map[x][y] && visited[nx][ny] == false){
            visited[nx][ny] = true;
            depth++;
            dfs(nx,ny);
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    init();
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m;
    N = n;
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
           map[i][j] = picture[i][j];     
        }
    }
    
    
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            if(visited[i][j] == false && map[i][j] != 0){
               
                dfs(i,j);
                number_of_area++;
                max_size_of_one_area = max(depth,max_size_of_one_area);
                depth = 0;
            }
        }
    }
    
    
   
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
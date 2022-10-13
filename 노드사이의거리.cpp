#include <iostream>
#include <vector>
using namespace std;

//백준 1240 노드사이의 거리

vector<int> graph[1001];
bool visited[1001];
int map[1001][1001]; //노드의 거리 저장
int Start,End;
int ans = 0;
 
void init(int n){ // visited배열 초기화
    for(int i = 0;i<=n;i++){
        visited[i] = false;
    }
}
 
void dfs(int start,int depth){
    if(start == End){ //현재 노드가 끝점이라면 ans갱신
        ans = depth;
        return;
    }
    if(visited[start]){
        return;
    }
    visited[start] = true;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        if(map[start][y] != 0){ //map에 값이 들어 있는 쪽으로 탐색하기
            dfs(y,depth+map[start][y]);
        }
        else if(map[start][y] == 0 && map[y][start] != 0){
            dfs(y,depth+map[y][start]);
        }
    }
 
}
int main(void){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        map[a][b] = c;
        map[b][a] = c;
    }
    for(int i = 0;i<m;i++){
        init(n);
        cin >> Start >> End;
        dfs(Start,0);
        cout << ans << '\n';
    }
}
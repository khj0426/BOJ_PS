#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[5001];
bool visited[5001];
int map[5001][5001];
int n;
long long ans = 0;


void init(){
    cin >> n;
    for(int i = 0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        map[a][b] = c;
        map[b][a] = c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int start,long long sum){

    if(sum > ans){
        ans = sum;
    }
    visited[start] = 1;
    
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        if(visited[y] == false){
            visited[y] = true;
            dfs(y,sum+map[start][y]);
            visited[y] = false;
        }
    }
    
}
int main(void){
    init();
    dfs(1,0);
    cout << ans;
}
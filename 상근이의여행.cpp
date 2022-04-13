#include <iostream>
#include <vector>
using namespace std;
//백준 상근이의 여행 9372

vector<int> graph[10000];
bool visited[10000];
int First = 0;
void dfs(int start){
    if(visited[start]){
        return;
    }
    First++;
    visited[start] = true;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        dfs(y);
    }
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        int start = 0;
        int n,m;
        cin >> n >> m;
        for(int i = 0;i<m;i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(1);
        cout << First-1 << '\n';
        First = 0;
        for(int i = 0;i<=n;i++){
            graph[i].clear();
        }
        for(int i = 0;i<=n;i++){
            visited[i] = false;
        }
    }
}
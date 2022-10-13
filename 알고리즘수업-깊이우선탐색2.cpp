#include <iostream>
#include <vector>
#include <algorithm>
//백준 알고리즘 수업- 깊이 우선탐색 2 24480번

using namespace std;

vector<int> graph[200000];
bool check[200000];
int is_visit[200000];
int index = 1;

void dfs(int start){
    if(check[start] == true){
        return;
    }
    check[start] = true;
    is_visit[start] = index;
    index++; 
    sort(graph[start].begin(),graph[start].end(),greater<int>());
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        dfs(y);
    }
}
int main(void){
    int n,m,i;
    cin >> n >> m >> i;
    for(int j = 0;j<m;j++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(i);
    for(int j = 1;j<=n;j++){
        cout << is_visit[j] << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

//백준 24479 알고리즘 수업-깊이 우선 탐색 1

using namespace std;
 
bool check[200000];
int Count[200000];
vector<int> graph[200000];
int first = 1;
 
void dfs(int start){
    if(check[start]){
        return;
    }
    check[start] = true;
    Count[start] = first;
    first++;
 
    sort(graph[start].begin(),graph[start].end());
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        dfs(y);
    }
}
 
int main(void){
    int n,m,First;
    cin >> n >> m >> First;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(First);
    for(int i = 1;i<=n;i++){
        cout << Count[i] << '\n';
    }
}
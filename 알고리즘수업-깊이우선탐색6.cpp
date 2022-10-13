#include <iostream>
#include <vector>
#include <algorithm>
//백준 알고리즘 수업- 깊이 우선 탐색 6

/*노드의 깊이와 노드 방문 순서의 곱 */
 
using namespace std;
vector<int> graph[200000];
bool visited[200000];
long long index[200000][2]; //i번 노드의 방문순서와 깊이를 저장하는 용도
int First = 1; //방문 순서
void dfs(int start,int depth){
    if(visited[start] == true){
        return;
    }
 
    index[start][0] = First; 
    First++;
    //방문순서 처리 과정
    index[start][1] = depth;
    //노드의 깊이 저장
    visited[start] = true;
     
    sort(graph[start].begin(),graph[start].end(),greater<int>());
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        dfs(y,depth+1);
    }
 
}
int main(void){
    int n,m,START;
    cin >> n >> m >> START;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    dfs(START,0);
    long long sum= 0;
    for(int i = 1;i<=n;i++){
        sum = sum + (index[i][0] * index[i][1]);
    }
 
    cout << sum;
}

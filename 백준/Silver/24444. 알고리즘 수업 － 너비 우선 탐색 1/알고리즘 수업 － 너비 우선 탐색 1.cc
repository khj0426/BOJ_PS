#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int n,m,r;
bool visited[100001];
int visited_order[100001];
vector<int> graph[100001];
int first = 1;
 
/*bfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
    for each v ∈ V - {R}
        visited[v] <- NO;
    visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
    enqueue(Q, R);  # 큐 맨 뒤에 시작 정점 R을 추가한다.
    while (Q ≠ ∅) {
        u <- dequeue(Q);  # 큐 맨 앞쪽의 요소를 삭제한다.
        for each v ∈ E(u)  # E(u) : 정점 u의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
            if (visited[v] = NO) then {
                visited[v] <- YES;  # 정점 v를 방문 했다고 표시한다.
                enqueue(Q, v);  # 큐 맨 뒤에 정점 v를 추가한다.
            }
    }
} */
void bfs(int start){  
  
    queue<int> q;
    q.push(start);
    visited[start] = true;

    visited_order[start] = first;
    first++;
    
    while(!q.empty()){
        int next = q.front();
        q.pop();
        
       sort(graph[next].begin(),graph[next].end());
        
        for(int i = 0;i<graph[next].size();i++){
            int y = graph[next][i];
            if(visited[y] == false){
                visited[y] = true;
                q.push(y);
                visited_order[y] = first;
                first++;
            }
        }
    }
    
}
 
int main(void){
    cin >> n >> m >> r;
 
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    bfs(r);
 
    for(int i = 1;i<=n;i++){
        if(visited[i] == false){
            cout << 0 << '\n';
        }
        else{
            cout << visited_order[i] << '\n';
        }
    }
}
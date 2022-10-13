#include <iostream>
#include <vector>
#include <algorithm>

//백준 24479 알고리즘 수업-깊이 우선 탐색 1

using namespace std;
 
bool check[200000]; //방문 여부를 알려줌
int Count[200000]; //정점의 방문 순서를 담을 배열
vector<int> graph[200000]; //그래프
int first = 1; //첫 방문 -> 그 후부터는 first값 +1 
 
void dfs(int start){ //dfs실행
    if(check[start]){ //방문처리된 정점이면 바로 나오기
        return;
    }
    check[start] = true; //방문처리가 안된다면 방문처리 하고
    Count[start] = first; //해당 정점의 방문 순서를 배열에 넣고
    first++; //first값 증가
 
    sort(graph[start].begin(),graph[start].end()); //인접 정점들을 오름차순 정렬 
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
        graph[a].push_back(b); //그래프를 연결하기
        graph[b].push_back(a);
    }
    dfs(First);
    for(int i = 1;i<=n;i++){
        cout << Count[i] << '\n';
    }
}
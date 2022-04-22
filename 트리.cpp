#include <iostream>
#include <vector>
using namespace std;

//백준 1068 트리

vector<int> graph[1000];
int parent[1000]; //부모 노드의 대한 정보
bool visited[1000];
int Remove; //제거 할 노드
int leaf; //루트 노드
 
void dfs(int start){
    if(start == parent[Remove]){ //현재 삭제노드의 부모인 경우
        return;
    }
    if(visited[start]){
        return;
    }
    visited[start] = true;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        dfs(y);
    }
}
 
int main(void){
    int count = 0;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(x == -1){
            leaf = i;
        }
        else{
            graph[x].push_back(i);
            parent[i] = x; //부모노드의 정보 저장
        }
    }
    cin >> Remove;
    dfs(Remove);//삭제할 노드를 대상으로 dfs실행

    graph[parent[Remove]].pop_back();//부모노드를 대상으로 pop하기
    /*ex)
        0-1-2-3차례대로 노드가 있을 때, 제거 노드가 2라면 2에서 dfs 살행 뒤
        0-1이 되어야 하고, 자식의 개수가 0인 노드는 1이어야 하는데
        0-1은 방문처리되지 않았고, 노드 0의 자식의 개수는 1, 노드 1의 자식의 개수는 1인
        상태이므로

        2의 부모노드인 1을 pop해줘야 한다
        */

    if(Remove == leaf){ //제거대상이 루트노드일 경우
        cout << '0';
    }
    else{
        for(int i = 0;i<n;i++){ //노드의 자식이 0이고 방문을 하지 않았다면
            if(graph[i].size() == 0 && visited[i] == false){
                count++;
            }
        }
        cout << count;
    }
}
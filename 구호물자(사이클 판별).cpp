//방법 1-> 플로이드로 사이클 판별

#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[101];
bool visited[101];
bool map[101][101];
bool flag = false;

int main(void){
    int n;
    cin >> n;
    for(int i = 1;i<=n-1;i++){
        int num;
        cin >> num;
        for(int j = 0;j<num;j++){
            int x;
            cin >> x;
            map[i][x] = 1;
        }
    }
    
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(map[i][k] == 1 && map[k][j] == 1){
                    map[i][j] = 1;
                }
            }
        }
    }
    
    for(int i = 1;i<=n;i++){
        if(map[1][i] == 1 && map[i][i] == 1){
            flag = true;
        }
    }
    if(flag == true){
        cout << "CYCLE";
    }
    else{
        cout << "NO CYCLE";
    }
   
}

//방법 2-> DFS로 사이클 찾기
/*DFS호출시 1->2->3->1로 사이클이 존재한다면(역방향 간선)
1부터 DFS 호출시 2 3 에 대해 방문처리를 하고, 3->1로 갈떄 해당 정점이 방문처리 되었고,
DFS(1)은 호출이 끝나지 않았다->역방향 간선이 존재하고 사이클이 존재함
*/
#include <iostream>
#include <vector>
using namespace std;
 
bool visited[101];
bool finished[101];
bool flag = false;
vector<int> graph[101];
 
void dfs(int start){
    visited[start] = true;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        if(visited[y] == false){
            dfs(y);
        }
        else if(finished[y] == false && visited[y] == true){
            flag = true;
        }
    }
    finished[start] = true;
}
 
int main(void){
    int n;
    cin >> n;
    for(int i = 1;i<=n-1;i++){
        int num;
        cin >> num;
        for(int j = 0;j<num;j++){
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }
 
    dfs(1);
    if(flag == false){
        cout << "NO CYCLE";
    }
    else{
        cout << "CYCLE";
    }
}
#include <iostream>
#include <vector>
using namespace std;
//백준 13237 Binary tree(노드의 깊이)

int parent;
int weight[21];
bool visited[21];
vector<int> graph[21];
void dfs(int start,int depth){ 
    if(visited[start]){
        return;
    }
    visited[start] = true;
    weight[start] = depth;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        dfs(y,depth+1);
    }
}
 
int main(void){
    int n;
    cin >> n;
    int arr[30];
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        if(arr[i] != -1){
            graph[i].push_back(arr[i]);
            graph[arr[i]].push_back(i);
 
        }
        else if(arr[i] == -1){
            parent = i;
        }
    }
    weight[parent] = 0;
    dfs(parent,1);
    for(int i = 1;i<=n;i++){
        cout << weight[arr[i]] << '\n';
    }
}
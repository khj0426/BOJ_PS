#include <iostream>
#include <vector>
//백준 11725 트리의 부모 찾기

using namespace std;

vector<int> graph[200000];
int index[200000];
bool check[200000];
void dfs(int start){
    if(check[start] == true){
        return;
    }
    check[start] = true;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        if(index[y] == 0){
        index[y] = start;
        }
        dfs(y);
    }
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for(int i = 2;i<=n;i++){
        if(index[i] != 0){
            cout << index[i] << '\n';
        }
    }
}
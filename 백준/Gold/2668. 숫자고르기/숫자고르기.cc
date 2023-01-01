#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 105
using namespace std;
 
bool visited[105];
bool finished[105];
bool cycle[105];
int n;
vector<int> graph[105];
set<int> allCycleNodes;
set<int>::iterator iter;
 
void init(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        int node;
        cin >> node;
        graph[i].push_back(node);
    }
}
 
void clearVisitedArray(){
    for(int i = 1;i<=MAX;i++){
        visited[i] = false;
    }
}
 
void dfs(int start){
    visited[start] = true;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        if(visited[y] == false){
            dfs(y);
        }
        else if(visited[y] == true && finished[y] == false){
           cycle[start] = true;
        }
 
    }
    finished[start] = true;
}
 
int main(void){
    init();
    for(int i = 1;i<=n;i++){
        clearVisitedArray();
        dfs(i);
        if(cycle[i] == true){
            for(int j = 1;j<=MAX;j++){
                if(visited[j] == true){
                    allCycleNodes.insert(j);
                }
            }
        }
    }
 
    cout << allCycleNodes.size() << '\n';
 
    for(iter = allCycleNodes.begin();iter != allCycleNodes.end();iter++){
        cout << *iter << '\n';
    }
}
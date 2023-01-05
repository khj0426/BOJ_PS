#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool checkImpossible = false;
int checked[1001];
bool visited[1001];
vector<int> graph[1001];

//이분 그래프 판별 

void bfs(int node){
        queue<int> q;
        q.push(node);
        checked[node] = 1;
        visited[node] = true;
        while(!q.empty()){
            int currentnode = q.front();
            int color = checked[currentnode];
            q.pop();
            for(int i = 0;i<graph[currentnode].size();i++){
                int nextnode = graph[currentnode][i];
                if(visited[nextnode] == false){
                     if(color == 1){
                        checked[nextnode] = 2;
                    }
                    else{
                        checked[nextnode] = 1;
                    }
                    visited[nextnode] = true;
                    q.push(nextnode);
                }
                else if(visited[nextnode] == true && checked[nextnode] == color){
                    checkImpossible = true;
                    return;
                }
            }
        }   
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        checkImpossible = false;
        
       
        cin >> n >> m;
        for(int i = 1;i<=n;i++){
            visited[i] = false;
            checked[i] = 0;
            graph[i].clear();
        }
        

        for(int i = 0;i<m;i++){
            int nodeA,nodeB;
            cin >> nodeA >> nodeB;
            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }
        
        //연결 그래프가 아닌 경우
        for(int i = 1;i<=n;i++){
            if(checked[i] == 0){
                bfs(i);
            }
        }
        
         if(checkImpossible == false){
            cout << "possible" <<'\n';
        }
        else{
            cout << "impossible" << '\n';
        }

       }
       
}

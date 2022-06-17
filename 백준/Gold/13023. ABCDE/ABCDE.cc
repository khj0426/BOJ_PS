#include <iostream>
#include <vector>
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
vector<int> graph[2001];
int frend[2000][2000];
bool visited[2001];
int cnt = 0;
int n,m;
bool valid = false;

void dfs(int start,int depth){
    if(depth == 4){
        cnt = 1;
        return;
    }
    visited[start] = true;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        if(visited[y] == false){
            visited[y] = true;
            dfs(y,depth+1);
            visited[y] = false;
        }
    }


}
 
void init(){
    for(int i = 0;i<n;i++){
        visited[i] = false;
    }
}
int main(void){
 
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
 
    for(int i = 0;i<n;i++){
        init();
        visited[i] = true;
        dfs(i,0);
        if(cnt == 1){
            cout << '1';
            return 0;

        }
     
    }
        cout << '0';
    return 0;
   
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
vector<int> graph[10001];
bool visited[10001];
int n,m;
int ans = 0;
int max_depth = 0;
vector<int> v;


void init(){
    for(int i = 1;i<=n;i++){
        visited[i] = false;
    }
}
void dfs(int start){

 
   
    visited[start] = true;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        if(visited[y] == false){
            ans++;
            dfs(y);
        }
    }
    
}

int main(void){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;

        graph[b].push_back(a);
    }
    
    for(int i = 1;i<=n;i++){
        init();
        ans = 0;
        dfs(i);
        if(ans > max_depth){
            v.clear();
            max_depth = ans;
            v.push_back(i);
        }
        else if(ans == max_depth){
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    
    
}

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k,x;
vector<int> graph[300001];
long long dt[300001];

void init(){
    cin >> n >> m >> k >> x;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for(int i = 1;i<=n;i++){
        dt[i] = -1;
    }
}

void bfs(){
    queue<int> q;
    q.push(x);
    dt[x] = 0;
    
    while(!q.empty()){
        int start = q.front();
        q.pop();
        for(int i = 0;i<graph[start].size();i++){
            int y = graph[start][i];
            if(dt[y] == -1){
                q.push(y);
                dt[y] = dt[start] + 1;
            }
        }
    }
}

int main(void){
    init();
    bfs();
    bool flag = false;
    vector<int> v;
    for(int i = 1;i<=n;i++){
        if(dt[i] == k){
            v.push_back(i);
            flag = true;
        }
    }
    if(flag == false){
        cout << -1;
    }
    else if(flag == true){
        sort(v.begin(),v.end());
        for(int i = 0;i<v.size();i++){
            cout << v[i] << '\n';
        }
    }
}
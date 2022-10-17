#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;
 
int dt[1001];
int n,m,x;
typedef pair<int,int> p;
 
vector<p> graph[1001];
int go_to[1001];
void init(){
    cin >> n >> m >> x;
    for(int i = 1;i<=n;i++){
       dt[i] = MAX;
    }
    for(int i = 0;i<m;i++){
        int a,b,cost;
        cin >> a >> b >> cost;
        graph[a].push_back({cost,b});
        //비용,노드
    }
}
 
void solve(int start,int endnode){
    priority_queue<p,vector<p>,greater<p>> q;
    q.push({0,start});
    dt[start] = 0;
    while(!q.empty()){
        int cost = q.top().first;
        int node = q.top().second;
        if(node == endnode){
            return;
        }
        q.pop();
 
        for(int i = 0;i<graph[node].size();i++){
            int nextcost = graph[node][i].first;
            int nextnode = graph[node][i].second;
            if(cost + nextcost < dt[nextnode]){
                dt[nextnode] = cost + nextcost;
                q.push({dt[nextnode],nextnode});
            }
        }
    }
}
 
void go_x(){
    for(int i = 1;i<=n;i++){
    	if(i == x){
    		continue;
    	}
        //i to x
        fill(dt,dt+n+1,MAX);
        solve(i,x);
        go_to[i] = dt[x];
        
    }
}

int main(void){
    init();
    go_x();

    int max_value = -987654321;
    for(int i = 1;i<=n;i++){
        fill(dt,dt+n+1,MAX);
        solve(x,i);
        int curcost = go_to[i];
        cout << curcost + dt[i] << '\n';
        if(curcost + dt[i] > max_value){
            max_value = curcost + dt[i];
        }

    }
    
}
 

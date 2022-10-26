#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 9999999999

//가능한 최대 경우 길의 수 * 최대 시간 300000*100000 -> 300억
 
using namespace std;

typedef long long ll;
 
int n,m;
vector<pair<ll,ll>> graph[100001];
bool index[100001];
ll dt[100001];

typedef pair<ll,ll> p;
void init(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> index[i];
        dt[i] = MAX;
    }
    for(int i = 0;i<m;i++){
        int a,b,weight;
        cin >> a >> b >> weight;
        graph[a].push_back({weight,b});
        graph[b].push_back({weight,a});
    }
}
 
void solve(int start){
    priority_queue<p,vector<p>,greater<p>> q;
    dt[start] = 0;
    q.push({dt[start],start});
    while(!q.empty()){
        ll weight = q.top().first;
        ll node = q.top().second;
        q.pop();
        //거리 테이블이 더 작은 경우 건너뜀
        if(dt[node] < weight){
            continue;
        }
        for(int i = 0;i<graph[node].size();i++){
            ll nextweight = graph[node][i].first;
            ll nextnode = graph[node][i].second;
            if(index[nextnode] == 0){
                if(weight + nextweight < dt[nextnode]){
                    dt[nextnode] = weight + nextweight;
                    q.push({dt[nextnode],nextnode});
                }
                else{
                    continue;
                }
            }
            else if(index[nextnode] == 1){
                if(nextnode == n-1){
                    if(weight + nextweight < dt[nextnode]){
                        dt[nextnode] = weight + nextweight;
                        q.push({dt[nextnode],nextnode});
                    }
                }
                else{
                     continue;
                }
               
            }
        }
    }
}
 
int main(void){
    init();
    solve(0);
    if(dt[n-1] == MAX){
        cout << -1;
    }
    else{
        cout << dt[n-1];
    }
}
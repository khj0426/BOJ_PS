#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;

int v,e,p;
int arr[5001];
vector<pair<int,int>> graph[5001];
//가중치 노드

typedef pair<int,int> P;

void input(){
    cin >> v >> e >> p;
    for(int i = 0;i<e;i++){
        int a,b,weight;
        cin >> a >> b >> weight;
        graph[a].push_back({weight,b});
        graph[b].push_back({weight,a});
    }

    for(int i = 1;i<=v;i++){
            arr[i] = MAX;
    }
}

void solve(int start){
    //가중치 노드
    priority_queue<P,vector<P>,greater<P>> q;
    q.push({0,start});
    arr[start] = 0;
    while(!q.empty()){
        
        int weight = q.top().first;
        int node = q.top().second;
        q.pop();
        for(int i = 0;i<graph[node].size();i++){
            int nextnode = graph[node][i].second;
            int nextweight = graph[node][i].first;
            if(arr[nextnode] > weight + nextweight){
                arr[nextnode] = weight + nextweight;
                q.push({arr[nextnode],nextnode});
            }
            else if(arr[nextnode] > weight + nextweight){
                arr[nextnode] = weight + nextweight;
                q.push({arr[nextnode],nextnode});
            }
        }
    }

}
int main(void){
    input();
    solve(1);
    int min_dt = arr[v]; //1 to 6
    int minjun = arr[p]; //1 to 4


    //4 to 6
    fill(arr,arr+v+1,MAX);
    solve(p);

    int minjun_dt = arr[v]; //4 to 6
    if(min_dt >= minjun + minjun_dt){
        cout << "SAVE HIM";   
    }
    else{
        cout << "GOOD BYE";
    }
   

}
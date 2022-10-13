#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;
 
int V,E,start;
vector<pair<int,int>> graph[20001];
int visited[20001];
 
void init(){
    fill(visited,visited+20001,MAX);
 
    cin >> V >> E;
    cin >> start;
 
    for(int i = 0;i<E;i++){
        int x,y,size_;
        cin >> x >> y >> size_;
        graph[x].push_back({y,size_}); //목적지와 가중치
 
    }
 
}
 
void Dykstra(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    visited[start] = 0;
    q.push({visited[start],start});
    //0과 시작정점
 
    while(!q.empty()){
        int width = q.top().first;
        int nextnode = q.top().second;
        q.pop();
        //인접 정점 중 거리가 가장 짧은 거로 감
 
        for(int i = 0;i<graph[nextnode].size();i++){
            int x = graph[nextnode][i].first; //좌표
            int y = graph[nextnode][i].second; //가중치
 
            if(y + width < visited[x]){
                visited[x] = y + width;
                q.push({visited[x],x}); //{갱신된 가중치, 좌표 넣기}
            }
        }
 
    }
 
}
 
int main(void){
    init();
    Dykstra();
    for(int i = 1;i<=V;i++){
        if(visited[i] == MAX){
            cout << "INF" << '\n';
        }
        else{
            cout << visited[i] << '\n';
        }
 
    }
}
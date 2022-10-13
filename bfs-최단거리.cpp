#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//최단거리 - bfs

/*start에서 시작해서 너비 우선 탐색 후, 시작점부터 각 정점까지 최단거리

distance[i] = start부터 i까지 최단거리
parent[i] = 너비우선탐색 스패닝 트리에서 i의 부모 번호(루트일 경우 자신) 

*/


vector<vector<int>> graph;

void bfs(int start,vector<int>&distance,vector<int>&parent){
	
	distance = vector<int>(graph.size(),-1);
	parent = vector<int>(graph.size(),-1);
	
	//방문할 정점 확인할 큐 
	queue<int> q;
	
	distance[start] = 0;
	parent[start] = start;
	
	q.push(start);
	while(!q.empty()){
		int next = q.front();
		q.pop();
		for(int i = 0;i<graph[next].size();i++){
			int there = graph[next][i];
			//방문할 정점 확인할 큐 
			if(distance[there] == -1){
				q.push(there);
				distance[there] = distance[next] + 1;
				parent[there] = next;
			} 
		}

	} 
	
} 

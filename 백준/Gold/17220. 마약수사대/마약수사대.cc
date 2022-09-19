#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
 
using namespace std;
int n,m,kill;
int ans = 0;
vector<int> graph[27];
bool visited[27];
int parent[27];
vector<char> target;
 
void init(){
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		char A,B;
		cin >> A >> B;
		graph[A-'A'].push_back(B-'A');
		target.push_back(A);
		target.push_back(B);
		parent[B-'A'] = A-'A';
 
	}
	cin >> kill;
	for(int i = 0;i<kill;i++){
		char about;
		cin >> about;
		visited[about-'A'] = true;
	}
}
 
void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int first = q.front();
		q.pop();
		for(int i = 0;i<graph[first].size();i++){
			int y = graph[first][i];
			if(visited[y] == false){
				ans++;
				visited[y] = true;
				q.push(y);
			}
		}
	}
}
 
int main(void){
	init();
 
	for(int i = 0;i<target.size();i++){
		if(visited[target[i]-'A'] == false && parent[target[i]-'A'] == false){
			bfs(target[i]-'A');
		}
	}
	cout << ans;
}
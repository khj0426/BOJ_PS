#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
 
int has_pan[100001];
vector<int> graph[100001];
int n,m;
int k;
 
void input(){
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		int A,B;
		cin >> A >> B;
		graph[A].push_back(B);
	}
	cin >> k;
	for(int i = 0;i<k;i++){
		int x;
		cin >> x;
		has_pan[x] = 2; //팬을 만나는 경우  
	}
}
 
void bfs(int start){
    if(has_pan[start] == 2){ //시작부터 팬이 존재 ->반례 3
        return;
    }
	queue<int> q;
	q.push(start);
	has_pan[start] = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0;i<graph[cur].size();i++){
			int y = graph[cur][i];
			if(has_pan[y] == 0){
				has_pan[y] = 1;
				q.push(y);
			}
		}
	}
} 
int main(void){
	input();
	bfs(1);
	bool flag = false;
	for(int i = 1;i<=n;i++){
        //이동할 수 없는 정점이고 팬을 만나지 않았다면
		if(graph[i].size() == 0 && has_pan[i] == 1){
			flag = true;
		}
	}
	if(flag == true){
		cout << "yes";
		return 0;
	}
	cout << "Yes";
}
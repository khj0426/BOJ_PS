#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
int items[51];
vector<int> graph[51];
int n;
bool visited[51];
int min(int a,int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}
int ans = 987654321;
char divide[51];
 
void init(){
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> items[i];
	}
	for(int i = 0;i<n;i++){
		int num_of_relation;
		cin >> num_of_relation;
 
		for(int j = 0;j<num_of_relation;j++){
			int first;
			cin >> first;
			graph[i].push_back(first-1);
            graph[first-1].push_back(i);
		}
	}
}
 
void bfs(int start){
 
	queue<int> q;
	q.push(start);
 	visited[start] = 1;
	while(!q.empty()){
		int first = q.front();
		q.pop();
		for(int i = 0;i<graph[first].size();i++){
			int y = graph[first][i];
			if(visited[y] == false && divide[y] == '1'){
				visited[y] = true;
				q.push(y);
 
			}
		}
 
	}
 
}
 
void Bfs(int start){
 
	queue<int> q;
	q.push(start);
 	visited[start] = 1;
	while(!q.empty()){
		int first = q.front();
		q.pop();
		for(int i = 0;i<graph[first].size();i++){
			int y = graph[first][i];
			if(visited[y] == false && divide[y] == '2'){
				visited[y] = true;
				q.push(y);
 
			}
		}
 
	}
 
}
 
void permutation(int N){
 
 
		vector<int> combinate;
		for(int j = 0;j<N;j++){
			combinate.push_back(1);
		}
		for(int j = 0;j<n-N;j++){
			combinate.push_back(0);
		}
		sort(combinate.begin(),combinate.end());
		do{
			vector<int> first;
			vector<int> second;
            int val_first = 0;
            int val_second = 0;
			for(int i = 0;i<n;i++){
                if(combinate[i] == 1){
                    first.push_back(i);
                    val_first += items[i];
                }
                else if(combinate[i] == 0){
                    second.push_back(i);
                    val_second += items[i];
                }
                divide[i] = '0';
                visited[i] = false;
            }
 
            for(int i = 0;i<first.size();i++){
                divide[first[i]] = '1';
            }
            for(int i = 0;i<second.size();i++){
                divide[second[i]] = '2';
            }
 
            if(!first.empty()){
                bfs(first[0]);
            }
            if(!second.empty()){
                Bfs(second[0]);
            }
            bool valid = false;
            for(int i = 0;i<n;i++){
                if(visited[i] == false){
                    valid = true;
                    break;
                }
            }
            if(valid == false){
                int diff = abs(val_first-val_second);
                ans = min(diff,ans);
            }
 
		}while(next_permutation(combinate.begin(),combinate.end()));
 
 
}
 
int main(void){
	init();
	for(int i = 0;i<n;i++){
		permutation(i);
	}
    if(ans == 987654321){
        ans = -1;
    }
 
    /*
     그래프의 정점(도시 수)가 2개이며, 두 정점을 연결하는 간선이 존재하지 않는 경우
 
    2
    3 4
    0
    0
    */
    

     
   cout << ans;
 
}
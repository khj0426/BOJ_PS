#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
 
int dt[1001];
int n,k;
int node_start;
int node_end;
string arr[1001];
int ans_distance;
vector<pair<int,int>> answer;
 
//거리가 1이면 해밍경로

//초기화와 입력 함수
void init(){
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        dt[i] = -1;
    }
    cin >> node_start >> node_end;
}
 
void bfs(int start){
    queue<pair<int,string>> q;
    q.push({start,arr[start]});
    dt[start] = 0;
    answer.push_back({start,dt[start]}); //{노드,최단거리 저장}
 
    while(!q.empty()){
        int node = q.front().first;
        string node_str = q.front().second;
        q.pop();
        if(node == node_end){ //종료 노드를 만났을 경우
            ans_distance = dt[node_end];
            return;
        }
 
        for(int i = 1;i<=n;i++){
            if(dt[i] != -1){
                continue;
            }
            int cnt = 0;
 
            for(int j = 0;j<k;j++){
                if(node_str[j] != arr[i][j]){
                    cnt++;
                }
                if(cnt >= 2){
                    break;
                }
            }
            
            if(cnt == 1 && dt[i] == -1){
                dt[i] = dt[node] + 1;
                q.push({i,arr[i]});
                answer.push_back({i,dt[i]});
            }
 
        }
    }
 
}
 
 
int main(void){
    init();
    bfs(node_start);
    //경로가 존재 하는 경우
    if(dt[node_end] != -1){
      vector<int> index;
      index.push_back(node_end);
      ans_distance--;
      //경로 역추적
        
      for(int i = answer.size()-1;i>=0;i--){
        if(ans_distance == answer[i].second){
            int cnt = 0;
            for(int j = 0;j<k;j++){
                int about_index = index[index.size()-1];
                if(arr[about_index][j] != arr[answer[i].first][j]){
                    cnt++;
                }
            }
            if(cnt == 1){
                index.push_back(answer[i].first);
                ans_distance--;
            }
        }
      }
      reverse(index.begin(),index.end());
      for(int i = 0;i<index.size();i++){
        cout << index[i] << ' ';
      }
    }
    //경로 존재 X
    else{
        cout << -1;
    }
 
}
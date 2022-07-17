#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*백준 17182 우주 탐사선 
기존 외판원 순회와 다른점-> 방문한 행성을 다시 방문할 수 있다.
기존 외판원 순회에서 예를 들어서 도시 2에서 도시 3으로 가려먼 방문한 도시는 다시 방문을 못하니까
경로가 1개밖에 존재 하지 않음 (2->3)

그러나 방문한 도시를 다시 방문 가능하다면
2->3으로 가는 경로는 (1->2->1->3, 1->2->1->4 등 더 많은 경우가 존재함)
-> [i][j] i->j로 가는 최단경로를 플로이드 와샬로 구해야 함
*/
 
int map[11][11];
bool visited[11];
int arr[11];
int n,k;
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
 
int ans = 987654321;
 
void dfs(int start){
   if(start == n){
       if(arr[0] != k){
           return;
       }
       int sum = 0;
       for(int i = 0;i<n-1;i++){
           sum += map[arr[i]][arr[i+1]];
       }
       ans = min(ans,sum);
       return;
   }
    for(int i = 0;i<n;i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[start] = i;
            dfs(start+1);
            visited[i] = false;
        }
    }
}
int main(void){
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
            }
        }
    }
    
    dfs(0);

    cout << ans;
}
#include <iostream>
using namespace std;
bool visited[100001];
int n;
int arr[100001];
int ans = 0;
void dfs(int start){
    if(visited[start]){
        return;
    }
    visited[start] = true;
    ans++;
    if(start+arr[start] < n){
        dfs(start+arr[start]);
    }
    if(start - arr[start] >= 0){
        dfs(start-arr[start]);
    }
 
}
int main(void){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int s;
    cin >> s;
 
 
    dfs(s-1);
    cout << ans;
}
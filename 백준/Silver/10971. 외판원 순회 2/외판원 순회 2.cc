#include <iostream>
#include <vector>
using namespace std;

int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int n;
int arr[11][11];
int a[11];
bool visited[11];
int ans = 987654321;
vector<int> v;

void dfs(int start){
    if(start == n){
        int sum = 0;
        for(int i = 0;i<n-1;i++){
            if(arr[a[i]][a[i+1]] == 0){
                return;
            }
            sum = sum + arr[a[i]][a[i+1]];
        }
    
      if(arr[a[n-1]][a[0]] != 0){
           sum = sum + arr[a[n-1]][a[0]];
           ans = min(sum,ans);
      }
     
        return;
        
    }
    for(int i = 0;i<n;i++){
        if(visited[i] == false){
            visited[i] = true;
            a[start] = i;
            dfs(start+1);
            visited[i] = false;
           
        }
    }
}
int main(void){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    dfs(0);
    cout << ans;
}
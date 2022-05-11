#include <iostream>
using namespace std;
int n,m;
int arr[10];
bool visited[10];

//백준 15652 N과 M(4)
 
void dfs(int start){
    bool not_valid = false; 
    if(m == start){
        for(int i = 0;i<m;i++){
            if(arr[i-1] > arr[i]){
                not_valid = true;
                break;
            }
        }
        if(not_valid == false){
            for(int i = 0;i<m;i++){
                cout << arr[i] << ' ';
            }
            cout << '\n';
 
        }
         return;
    }
    for(int i = 1;i<=n;i++){
        visited[i] = true;
        arr[start] = i;
        dfs(start+1);
        visited[i] = false;
    }
}
int main(void){
    cin >> n >> m;
    dfs(0);
}
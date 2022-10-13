#include <iostream>
#include <vector>
using namespace std;\
//백준 15650 N과 M(2)

int n,m;
bool isvisited[9];
int arr[9];
vector<pair<int,int>> v;
 
void dfs(int start){
 
    if(start == m){
        bool is_increase = true;
        for(int i = 0;i<m;i++){
            if(arr[i] < arr[i-1]){
                is_increase = false;
            }
        }
        if(is_increase == true){
            for(int i = 0;i<m;i++){
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }
 
        return;
    }
    for(int i = 1;i<=n;i++){
        if(isvisited[i] == false){
            isvisited[i] = true;
            arr[start] = i;
            dfs(start+1);
            isvisited[i] = false;
        }
    }
}
 
int main(void){
    cin >> n >> m;
    dfs(0);
}
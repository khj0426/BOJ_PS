#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[11];
int arr[11][11];

vector<int> Value;
vector<int> v;
int max_ = -1;

void dfs(int start,int sum){
    if(start == 11){
        if(max_ < sum){
            max_ = sum;
        }
        return;
    }
    for(int i = 0;i<11;i++){
        if(visited[i] == false && arr[start][i] != 0){
            visited[i] = true;
            Value.push_back(i);
            dfs(start+1,sum+arr[start][i]);
            Value.pop_back();
            visited[i] = false;
        }
    }
}


int main(void){
    int t;
    cin >> t;
    while(t--){
        v.clear();
        for(int i = 0;i<11;i++){
            visited[i] = false;
        }
        max_= -1;
        
        for(int i = 0;i<11;i++){
            for(int j = 0;j<11;j++){
                cin >> arr[i][j];
            }
            v.push_back(i);
        }
        
        dfs(0,0);
        cout << max_ << '\n';
    }
  
    
}
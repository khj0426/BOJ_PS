#include <iostream>
#include <vector>
using namespace std;

int ans = 987654321;
int n,m;
vector<int> v;
vector<int> problem_set[11];

void dfs(int start){
    if(start == m){
        bool arr[11] = {false, };
        bool valid = false;
        for(int i = 0;i<v.size();i++){
           int v_element = v[i];
           for(int j = 0;j<problem_set[v[i]].size();j++){
               int y = problem_set[v[i]][j];
               if(arr[y] == true){
                   continue;
               }
               else if(arr[y] == false){
                   arr[y] = true;
               }
           } 
        }
        
        for(int i = 0;i<n;i++){
            if(arr[i] == false){
                valid = true;
                break;
            }
        }
        if(valid == false){
            if(v.size() < ans){
                ans = v.size();
            }
        }
        return;
    }
    dfs(start+1);
    v.push_back(start);
    dfs(start+1);
    v.pop_back();
}

int main(void){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int t;
        cin >> t;
        for(int j = 0;j<t;j++){
            int element;
            cin >> element;
            problem_set[i].push_back(element-1);
        }
    }
    dfs(0);
    if(ans == 987654321){
        cout << -1;
        return 0;
    }
    cout << ans;
}

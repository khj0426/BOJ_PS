#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int n,m;
int cnt = 0;
vector<int> map;
bool visited[11];
int arr[11];
vector<int> DATA_;
set<string> s;
set<string>::iterator iter;
 
void dfs(int start){
    bool valid = false;
    bool index[11] = {false, };
    if(start == n){
        string str = "";
        for(int i = 0;i<DATA_.size();i++){
            if(find(map.begin(),map.end(),DATA_[i]) == map.end()){
                valid = true;
                break;
            }
        }
        if(valid == false){
            for(int i = 0;i<map.size();i++){
                str.append(to_string(map[i]));
            }
            cnt++;
 
        }
        return;
    }
    for(int i = 0;i<=9;i++){
        if(visited[i] == false){
            visited[i] = true;
            map.push_back(i);
            dfs(start+1);
            map.pop_back();
            visited[i] = false;
        }
        else if(visited[i] == true){
            map.push_back(i);
            dfs(start+1);
            map.pop_back();
        }
    }
 
}
 
 
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0;i<=9;i++){
        arr[i] = i;
    }
 
    for(int i = 0;i<m;i++){
        int x;
        cin >> x;
        DATA_.push_back(x);
        visited[x] = 1;
    }
 
    dfs(0);
    cout << cnt;
}
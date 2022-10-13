#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
int parents[51]; //같은 그래프면 같은 부모
int n,m; //사람의 수 파티의 수
map<int,bool> truth; //진실을 아는 사람
map<int,bool>::iterator iter;
vector<int> parth [51];//파티마다 오는 사람의 수
 
 
int find(int x){
    if(parents[x] == x){
        return x;
    }
    else{
        parents[x] = find(parents[x]);
        return parents[x];
    }
}
 
void merge(int A,int B){ //union 연산
 
    int a = find(A);
    int b = find(B);
    if(a == b){
        return;
    }
 
    if(truth[a] == 1){
        truth[b] = 1;
    }
    else if(truth[b] == 1){
        truth[a] = 1;
    }
 
    if(a < b){
        parents[b] = a;
    }
    else{
        parents[a] = b;
    }
 
}
 
 
 
void input(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){ //부모를 자기 자신으로 초기화
        parents[i] = i;
    }
 
    int kill;
    cin >> kill;
    for(int i = 0;i<kill;i++){
        int node;
        cin >> node;
        truth[node] = 1;
    }
 
}
 
void input_parth_union(){ //각 파티마다 오는 사람 union연산
    for(int i = 1;i<=m;i++){
        int participate;
        cin >> participate;
 
        for(int j = 0;j<participate;j++){
            int num;
            cin >> num;
            parth[i].push_back(num);
        }
    }
}
 
void merge_participate(){
     for(int i = 1;i<=m;i++){
        for(int j = 0;j<parth[i].size();j++){
            for(int k = 0;k<parth[i].size();k++){
                merge(parth[i][j],parth[i][k]);
            }
        }
    }
}
 
 
 
 
int main(void){
    input();
    input_parth_union();
    merge_participate();
    int ans = 0;
 
    for(int i = 1;i<=m;i++){
        bool valid = false;
        for(int j = 0;j<parth[i].size();j++){
            if(truth[find(parth[i][j])] == 1 || truth[parth[i][j]] == 1){
                valid = true;
                break;
            }
        }
        if(valid == false){
 
            ans++;
        }
 
    }
    cout << ans;
}
 
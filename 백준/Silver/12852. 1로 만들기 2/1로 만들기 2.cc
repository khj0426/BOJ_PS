#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int n;
int dt[1000001];
int range_(int n){
    if(n < 1 || n > 1000000){
        return -1;
    }
    return 1;
}
 
int ans = 0;
 
void bfs(int start){
    queue<int> q;
    q.push(start);
    dt[start] = 0;
    while(!q.empty()){
        int next = q.front();
        q.pop();
        if(next == 1){
            return;
        }
        if((next%3 == 0)){
            if(dt[next/3] > dt[next] + 1){
                dt[next/3] = dt[next] + 1;
                q.push(next/3);
            }
        }
        if((next%2 == 0)){
            if(dt[next/2] > dt[next] + 1){
                dt[next/2] = dt[next] + 1;
                q.push(next/2);
            }
        }
            if(dt[next-1] > dt[next] + 1){
                dt[next-1] = dt[next] + 1;
                q.push(next-1);
            }
    }
}
 
int valid(int a,int b){
    if(a * 3 == b){
        return 1;
    }
    if(a *2 == b){
        return 1;
    }
    if(a+1 == b){
        return 1;
    }
    return -1;
}
 
int main(void){
    cin >> n;
    for(int i = 1;i<=n;i++){
        dt[i] = 987654321;
    }
    bfs(n);
 
    cout << dt[1] << '\n';
    vector<int> v;
    v.push_back(1);
 
    int first = dt[1] - 1;
    int first_value = 1;
    for(int i = 2;i<=n;i++){
        if(first == dt[i]){
            //연결되어있는지
            if(valid(first_value,i) == 1){
                first_value = i;
                v.push_back(i);
                first--;
            }
        }
    }
 
    reverse(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        cout << v[i] << ' ';
    }
 
 
}
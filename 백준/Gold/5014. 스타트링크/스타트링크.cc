#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
int f,s,g,u,d;
int check(int n){
    if(n <= 0 || n > 1000000){
        return -1;
    }
    return 1;
}
 
int dt[1000001];
 
void init(){
    cin >> f >> s >> g >> u >> d;
    for(int i = 0;i<=f;i++){
        dt[i] = -1;
    }
}
 
 
void bfs(int start){
    queue<int> q;
    q.push(start);
    dt[start] = 0;
 
    while(!q.empty()){
        int first = q.front();
        q.pop();
        if(check(first+u) == 1 && dt[first+u] == -1){
            dt[first+u] = dt[first] + 1;
            q.push(first+u);
        }
        if(check(first-d) == 1 && dt[first-d] == -1){
            dt[first-d] = dt[first] + 1;
            q.push(first-d);
        }
    }
}
int main(void){
	init();
 
    bfs(s);
    if(dt[g] == -1){
    	cout << "use the stairs";
    	return 0;
    }
    cout << dt[g];
}
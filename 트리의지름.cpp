#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
 
using namespace std;
 
int widtharray[10010];
int n;
int maxwidth = 0;
vector<pair<int,int>> graph[10010];
 
void init(){
    cin >> n;
    for(int i = 0;i<n-1;i++){
        int parent,child,width;
        cin >> parent >> child >> width;
        graph[parent].push_back({child,width});
        graph[child].push_back({parent,width});
    }
}
 
void bfs(int firstnode){
    queue<int> q;
    q.push(firstnode);
    widtharray[firstnode] = 0;
 
    while(!q.empty()){
        //first is node ,second is width
        int nextnode = q.front();
        q.pop();
        for(int i = 0;i<graph[nextnode].size();i++){
            int y = graph[nextnode][i].first;
            if(widtharray[y] == -1){
                widtharray[y] = widtharray[nextnode] + graph[nextnode][i].second;
                maxwidth = max(maxwidth,widtharray[y]);
                q.push(y);
            }
        }
 
    }
}
int main(void){
    init();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            widtharray[j] = -1;
        }
        bfs(i);
    }
    cout << maxwidth;
    return 0;
}
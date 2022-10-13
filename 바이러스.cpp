#include <iostream>
#include <vector>
//백준 2606 바이러스

using namespace std;

vector<int> graph[101];
bool visit[101];
int count = 0;
int n;

void dfs(int start){

   if(visit[start] == true){
       return;
   }
    visit[start] = true;
    count++;
    for(int i = 0;i<graph[start].size();i++){
        int y = graph[start][i];
        dfs(y);
    }


}
int main(void){

    cin >> n;
    int m;
    cin >> m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout << count-1;
}

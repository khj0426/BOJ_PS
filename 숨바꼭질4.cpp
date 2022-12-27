#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100000
using namespace std;
 
int n,k;
 
int dt[MAX + 1];
void input(){
    cin >> n >> k;
    for(int i = 0;i<=MAX;i++){
        dt[i] = 987654321;
    }
}
 
bool isValid(int node){
    if(node > MAX || node < 0){
        return false;
    }
    return true;
}
 
void bfs(int start){
    queue<pair<int,int>> q;
    dt[start] = 0;
    q.push({dt[start],start});
 
    while(!q.empty()){
        int width = q.front().first;
        int node = q.front().second;
        q.pop();
        if(node == k){
            break;
        }
        if(isValid(node + 1) && width + 1 < dt[node + 1]){
            dt[node+1] = width + 1;
            q.push({dt[node+1],node+1});
        }
        if(isValid(node - 1) && width + 1 < dt[node - 1]){
            dt[node-1] = width + 1;
            q.push({dt[node-1],node-1});
        }
        if(isValid(node * 2) && width + 1 < dt[node *2]){
            dt[node*2] = width + 1;
            q.push({dt[node*2],node*2});
        }
    }
 
}
 
bool isConnected(int prevDist,int nextDist){
    if(prevDist + 1 == nextDist){
        return true;
    }
 
    if(prevDist - 1 == nextDist){
        return true;
    }
 
    if(prevDist * 2 == nextDist){
        return true;
    }
 
    return false;
}
 
vector<pair<int,int>> findAlldistance(int k){
    vector<pair<int,int>> ans;
    queue<pair<int,int>> q;
    q.push({dt[k],k});
    ans.push_back({dt[k],k});
 
    while(!q.empty()){
        int width = q.front().first;
        int node = q.front().second;
        q.pop();
        if(node == n){
            break;
        }
 
        if(isValid(node-1) && dt[node-1] == width - 1){
            q.push({dt[node-1],node-1});
            ans.push_back({dt[node-1],node-1});
        }
        if(isValid(node+1) && dt[node+1] == width - 1){
            q.push({dt[node+1],node+1});
            ans.push_back({dt[node+1],node+1});
        }
        if(isValid(node/2) && dt[node/2] == width - 1){
            q.push({dt[node/2],node/2});
            ans.push_back({dt[node/2],node/2});
        }
 
    }
    return ans;
}
 
int main(void){
    input();
    bfs(n);
    vector<pair<int,int>> Answer = findAlldistance(k);
    int startWidth = dt[k];
    int startNode = k;
    vector<int> reversed_Answer;
    cout << dt[k] << '\n';

    reversed_Answer.push_back(startNode);
    for(int i = 0;i<Answer.size();i++){
        if(Answer[i].first == startWidth - 1 && isConnected(Answer[i].second,startNode)){
            reversed_Answer.push_back(Answer[i].second);
            startWidth = Answer[i].first;
            startNode = Answer[i].second;
           
        }
    }

    reverse(reversed_Answer.begin(),reversed_Answer.end());
    for(int i = 0;i<reversed_Answer.size();i++){
        cout << reversed_Answer[i] << ' ';
    }
 
}
 
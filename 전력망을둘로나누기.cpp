#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[101];

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    for(int i = 0;i<wires.size();i++){
        vector<int> graph[101];
        for(int j = 1;j<=n;j++){
            visited[j] = false;
        }
        for(int j = 0;j<wires.size();j++){
            if(i != j){
                int first = wires[j][0];
                int second = wires[j][1];
                graph[first].push_back(second);
                graph[second].push_back(first);
            }
        }
        
        int first=0;
        int second=0;
        
        for(int i = 1;i<=n;i++){
            if(visited[i] == false){
                queue<int> q;
                visited[i] = true;
                q.push(i);
                if(first == 0){
                    first++;
                    while(!q.empty()){
                        int cur = q.front();
                        q.pop();
                        for(int k = 0;k<graph[cur].size();k++){
                            int next = graph[cur][k];
                            if(!visited[next]){
                                q.push(next);
                                visited[next] = true;
                                first++;
                            }
                        }
                    }
                    
                }
                else{
                    second++;
                    while(!q.empty()){
                        int cur = q.front();
                        q.pop();
                        for(int k = 0;k<graph[cur].size();k++){
                            int next = graph[cur][k];
                            if(!visited[next]){
                                q.push(next);
                                visited[next] = true;
                                second++;
                            }
                        }
                    }
                }
                
                
            }
        }
        
        answer = min(answer,abs(first-second));
        
        
    }
    return answer;
}
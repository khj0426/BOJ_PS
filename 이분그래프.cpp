#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> graph[20001];
        int color[20001];
        int V, E;
        cin >> V >> E;

        memset(color, -1, sizeof(color));

        for (int i = 0; i < E; i++) {
            int firstNode, secondNode;
            cin >> firstNode >> secondNode;
            graph[firstNode].push_back(secondNode);
            graph[secondNode].push_back(firstNode);
        }
        bool flag = false;
        // 0과 1 색상
        for (int i = 1; i <= V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                

                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();

                    for (int i = 0; i < graph[cur].size(); i++) {
                        int next = graph[cur][i];

                        if (color[next] == -1) {
                            if (color[cur] == 0) {
                                color[next] = 1;
                            } else if (color[cur] == 1) {
                                color[next] = 0;
                            }
                            q.push(next);
                        } else {
                            if (color[cur] == color[next]) {
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        if (flag) {
            cout <<  "NO" << '\n';
        } 
        else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}
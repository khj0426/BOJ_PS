#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>


using namespace std;

int visited[101][101];
int arr[101][101];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int Z = 2;

//걍 좌표 뒤집으면 되는거 아님? ㄴㄴ


int main(void){
    int n,m;
    int k;
    
    int count = 0;
    queue<pair<int,int>> q;
    vector<int> v;
    
    cin >> n >> m >> k;
    while(k--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
       //00 -> 05
       // 75 -> 70
        
        
        //01 -> 04
        //70 -> 75
        
        //11 -> 14
        
        y1 = n - y1;
        y2 = n - y2;
        
        //x는 고정  ㄱ
        
        int minX = min(x1,x2);
        int maxX = max(x1,x2);
        
        int minY = min(y1,y2);
        int maxY = max(y1,y2);
        
        for(int i = minY;i<maxY;i++){
            for(int j = minX;j<maxX;j++){
                visited[i][j] = 1;
            }
        }
        
    }
    
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] == 0){
                count++;
                visited[i][j] = Z;
                q.push({i,j});
                
                while(!q.empty()){
                    int nx = q.front().first;
                    int ny = q.front().second;
                    q.pop();
                    
                    for(int z = 0;z<4;z++){
                        int X = nx + dx[z];
                        int Y = ny + dy[z];
                        if(X < 0 || Y < 0 || X >= n || Y >= m){
                            continue;
                        }
                        if(visited[X][Y] == 0){
                            visited[X][Y] = Z;
                            q.push({X,Y});
                        }
                    }
                }
                Z++;
            }
        }
    }
    cout << count << '\n';
    for(int i = 2;i<Z;i++){
        int areaC = 0;
        for(int j = 0;j<n;j++){
            for(int z = 0;z<m;z++){
                if(visited[j][z] == i){
                    areaC++;
                }
            }
        }
        v.push_back(areaC);
    }
    sort(v.begin(),v.end());
    
    for(int i = 0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    
    
        
}
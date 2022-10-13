#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#define MAX 987654321
using namespace std;
 
vector<pair<int,int>> v;
map<int,int> m;
int n,t;
int arr[1001][1001];
void init(){
    for(int i = 1;i<=1000;i++){
        for(int j = 1;j<=1000;j++){
            arr[i][j] = MAX;
        }
    }
    cin >> n >> t;
    for(int i = 1;i<=n;i++){
        int type;
        cin >> type;
        if(type == 1){
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
            m[i] = t;
        }
        else if(type == 0){
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
            m[i] = MAX;
        }
    }
 
}
 
void set_distance(){
    for(int i = 1;i<=n;i++){
        if(m[i] == MAX){
            for(int j = 1;j<=n;j++){
                int x1 = v[i-1].first;
                int y1 = v[i-1].second;
                int x2 = v[j-1].first;
                int y2 = v[j-1].second;
                arr[i][j] = min(arr[i][j],abs(x1-x2) + abs(y1-y2));
            }
        }
        else if(m[i] == t){
            for(int j = 1;j<=n;j++){
                if(m[j] == t){
                    arr[i][j] = min(arr[i][j],t);
                }
               
                int x1 = v[i-1].first;
                int y1 = v[i-1].second;
                int x2 = v[j-1].first;
                int y2 = v[j-1].second;
                arr[i][j] = min(arr[i][j],abs(x1-x2) + abs(y1-y2));
               
            }
        }
    }
}
 
int main(void){
    init();
    set_distance();
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
    }
 
    int query;
    cin >> query;
    for(int i = 0;i<query;i++){
        int a,b;
        cin >> a >> b;
        cout << arr[a][b] << '\n';
    }
 
}

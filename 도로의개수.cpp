#include <iostream>
#include <cmath>
#include <set>
#include <cstring>
using namespace std;
 
typedef long long ll;
 
ll dp[105][105];
int dx[2] = {0,1};
int dy[2] = {1,0};
set <pair<int,int>> s[101][101];
 
int n,m;
int k;
 
void init(){
    cin >> n >> m;
    cin >> k;
    while(k--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        s[a][b].insert({c,d});
        s[c][d].insert({a,b});
    }
    memset(dp,-1,sizeof(dp));
}
 
ll Solve(int x,int y){
    if(x == n && y == m){
        return 1;
    }
    ll &ret = dp[x][y];
 
    if(ret != -1){
        return ret;
    }
 
    ret = 0;
    for(int i = 0;i<2;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > n || ny > m){
            continue;
        }
        if(s[x][y].find({nx,ny}) != s[x][y].end()){
            continue;
        }
        ret += Solve(nx,ny);
    }
    return ret;
 
}
 
int main(void){
    init();
    cout << Solve(0,0);
}
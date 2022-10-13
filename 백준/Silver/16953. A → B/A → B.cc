#include <iostream>
using namespace std;

typedef long long ll;
ll a,b;
ll ans = 9987654321;
ll min(ll a,ll b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
 
void input(){
    cin >> a >> b;
 
}
 
void dfs(ll n,ll start){
    if(n >= b){
        if(n == b){
            ans = min(ans,start);
        }
        return;
    }
    dfs(n*2,start+1);
    dfs(n*10 + 1,start+1);
}
 
int main(void){
    input();
    dfs(a,0);
    if(ans == 9987654321){
        cout << -1;
        return 0;
    }
    else{
        cout << ans + 1;
        return 0;
    }
}
#include <iostream>
#define mod 1000000007

//백준 14494 다이나믹이 뭐예요?
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    long long dp[1002][1002];
 
    int n,m;
    cin >> n >> m;
 
    int big = max(n,m);
    for(int i = 1;i<=big;i++){
        for(int j = 1;j<=big;j++){
            dp[i][j] = 1;
        }
    }
 
 
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(j == 1){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i-1][j] % mod + dp[i][j-1] % mod + dp[i-1][j-1] % mod)%mod;
            }
        }
    }
 
 
 
    cout  << dp[n][m];
 
 
}
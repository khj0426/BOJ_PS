#include <iostream>
//백준 20152 Game Addiction
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
 
int main(void){
    long long dp[31][31];
 
    for(int i = 0;i<=30;i++){
        for(int j = 0;j<=30;j++){
            dp[i][j] = 0;
        }
    }
 
    int n,m;
    cin >> n >> m;
 
    int big = max(n,m);
    int small = min(n,m);
 
    long long MAX = 0;
    for(int i = small;i<=big;i++){
        for(int j = small;j<=i;j++){
            if(j == small){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            MAX = max(dp[i][j],MAX);
        }
    }
  cout << MAX;
}
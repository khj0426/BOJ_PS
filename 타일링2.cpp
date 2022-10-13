#include <iostream>

//백준 2*n 타일링 2 11727번
#define mod 10007
using namespace std;
int main(void){
    int dp[1000];
    for(int i = 1;i<=1000;i++){
        if(i == 1){
            dp[i] = 1;
        }
        else if(i == 2){
            dp[i] = 3;
        }
        else{
            dp[i] = (dp[i-1] + 2*dp[i-2])%mod;
        }
        
       
    }
    
    int n;
    cin >> n;
    cout << dp[n];
}
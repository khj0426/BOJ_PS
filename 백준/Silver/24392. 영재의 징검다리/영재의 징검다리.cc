#include <iostream>
#define MOD 1000000007
using namespace std;
long long dp[1001][1001];
int map[1001][1001];
int main(void){
 
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            if(i == n-1 && map[i][j] == 1){
                dp[i][j] = 1;
            }
        }
    }
    
    long long sum = 0;
    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<m;j++){
            if(map[i][j] == 1){
                if(j == 0){
                    if(map[i+1][j] == 1){
                        dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
                        
                    }
                    if(map[i+1][j+1] == 1){
                        dp[i][j] = (dp[i][j] + dp[i+1][j+1]) % MOD;
                    }
                }
                else if(j == m-1){
                    if(map[i+1][j] == 1){
                        dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
                    }
                    if(map[i+1][j-1] == 1){
                        dp[i][j] = (dp[i+1][j-1] + dp[i][j]) % MOD;
                    }
                }
                else{
                    if(map[i+1][j-1] == 1){
                         dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD;
                    }
                    if(map[i+1][j] == 1){
                         dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
                    }
                    if(map[i+1][j+1] == 1){
                         dp[i][j] = (dp[i][j] + dp[i+1][j+1]) % MOD;
                    }
                }
                
            }
 
        }
 
    }
 
    for(int i = 0;i<m;i++){
        if(map[0][i] == 1){
            sum += (dp[0][i]);
        }
    }
    cout << sum % MOD;
}
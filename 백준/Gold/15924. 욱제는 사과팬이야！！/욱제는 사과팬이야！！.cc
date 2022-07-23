#include <iostream>
#define MOD 1000000009
using namespace std;
typedef long long ll;
 
char arr[3001][3001];
int n,m;
ll dp[3001][3001];
 
int main(void){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
            dp[i][j] = 1;
        }
    }
 
    dp[0][0] = 1;
    bool is_end = false;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
             if(i == n-1 && j == m-1){
                 is_end = true;
                 break;
             }
            if(arr[i][j] == 'B'){
                if(i+1 < n){
                    dp[i+1][j] = dp[i+1][j]%MOD + dp[i][j]%MOD;
                }
                if(j+1 < m){
                    dp[i][j+1] = dp[i][j+1] % MOD + dp[i][j] % MOD;
                }
            }
            else if(arr[i][j] == 'E'){
                if(j+1 < m){
                    dp[i][j+1] = dp[i][j+1] % MOD + dp[i][j] % MOD;
                }
            }
            else if(arr[i][j] == 'S'){
                if(i+1 < n){
                    dp[i+1][j] = dp[i+1][j] % MOD + dp[i][j] % MOD;
                }
            }
        }
        if(is_end == true){
            break;
        }
 
    }
    cout << dp[n-1][m-1] % MOD;
}
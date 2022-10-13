#include <iostream>
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
    int arr[301][301];
    int dp[301][301];
    int n,m;
    cin >> n >> m;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
        }
    }
 
    dp[0][0] = arr[0][0];
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else{
                dp[i][j] = max((dp[i][j-1] + arr[i][j]),(dp[i-1][j] + arr[i][j]));
            }
        }
    }
    cout << dp[n-1][m-1];
 
}
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
    //백준 9465 스티커
    int t;
    cin >> t;
    while(t--){
        int dp[100001][2];
        int arr[100001][2];
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> arr[i][0];
        }
        for(int i = 1;i<=n;i++){
            cin >> arr[i][1];
        }
        for(int i = 1;i<=n;i++){
            if(i == 1){ //1번쨰 2번쨰 일떄 제외하고
                dp[i][0] = arr[i][0];
                dp[i][1] = arr[i][1];
            }
            else if(i == 2){
                dp[i][0] = dp[i-1][1] + arr[i][0];
                dp[i][1] = dp[i-1][0] + arr[i][1];
            }
            else{
                //dp[i][0]은 직전의 dp[i-1][1] + arr[i][0] 또는,
                //i-2 dp테이블의[1] + arr[i][0] 중 큰 값
                dp[i][0] = max(dp[i-1][1] + arr[i][0],dp[i-2][1] + arr[i][0]);
                dp[i][1] = max(dp[i-1][0] + arr[i][1],dp[i-2][0] + arr[i][1]);
            }
        }
        cout << max(dp[n][0],dp[n][1]) << '\n';
 
    }
 
}
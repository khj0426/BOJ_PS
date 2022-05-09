#include <iostream>
using namespace std;
//백준 11048 이동하기

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    int dp[1001][1001];
    int arr[1001][1001];
 
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){ //배열 입력받고 DP테이블 0으로 초기화
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];  
            dp[i][j] = 0;
        }
    }
 
    dp[0][0] = arr[0][0]; //처음 DP테이블은 배열의 값으로
    for(int i = 1;i<m;i++){ //0번째일때 가능한 경우는 배열값 + 왼쪽 DP테이블 값
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }
 
    for(int i = 1;i<n;i++){ //0번 생략하고 1번쨰부터
        for(int j = 0;j<m;j++){
            if(j == 0){ //j가 0일떄는 하나의 경우(위에서 내려오는 경우)
                dp[i][j] = arr[i][j] + dp[i-1][j];
            }
            else{ //j가 0이 아닐때의 경우
                dp[i][j] = max((arr[i][j]+dp[i-1][j]),(arr[i][j] + dp[i-1][j-1]));
                dp[i][j] = max(dp[i][j],(arr[i][j]+dp[i][j-1]));
            }
            }
 
        }
 
 
    cout << dp[n-1][m-1];
}
#include <iostream>
#include <algorithm>
#include <cstring>


//냅색 문제 정리
using namespace std;
int dp[101][100001];
pair<int,int> arr[101];
//물건의 무게와 가치

int main(void){
    int n,k;
    cin >> n >> k;

    for(int i = 1;i<=n;i++){
        int w,v;
        cin >> w >> v;

        //무게와 가치
        arr[i] = {w,v};
    }


//물건과 무게
//(i,j) -> 1부터 i까지 물건으로 j이하의 무게를 채울떄 최대 가치

//1부터 3까지 물건으로 7이하의 무게를 채울떄 최대 가치
/*

dp[3][7] = max(dp[2][7],dp[2][5] + 물건 3의 가치)

dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i][j]의 무게] + arr[i][j]의 가치)
*/
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            if(j - arr[i].first >= 0){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i].first] + arr[i].second);
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }

    cout << dp[n][k];
}
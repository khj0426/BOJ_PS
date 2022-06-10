#include <iostream>
using namespace std;
typedef long long ll;

//백준 10164 격자상의 격로
/*전체 이동할수 있는 경우 - 0를 거쳐서 이동하는 경우를 뺴주기*/

int main(void) {
    ll arr[20][20];
    ll dp[20][20];

    int number = 1;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) { //1부터 순서대로 번호 매기기
        for (int j = 1; j <= m; j++) {
            arr[i][j] = number;
            number++;
            dp[i][j] = 1;
        }
    }



    for (int i = 1; i <= n; i++) { //n*m경로로 가는 모든 경우의 수 
        for (int j = 1; j <= m; j++) {
            if (j != 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }

        }
    }

    ll cur_dp_count = dp[n][m]; //전체 경우의 수
    ll zero_dp = 0;//0의 x,y좌표와 0을 거쳐서 가는 경우
    int x = 0;
    int y = 0;

    bool is_find = false; //n*m에서 0을 찾으면 true로
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            if (arr[i][j] == k) { //찾으면 해당 xy값 0으로 바꾸고 좌표 저장 + 루프 탈출
                is_find = true;
                dp[i][j] = 0;
                x = i;
                y = j;
                break;
            }
        }
        if (is_find == true) {
            break;
        }
    }

    for (int i = x; i <= n; i++) { //0에서 n*m으로 가는 경로 구하기
        for (int j = y; j <= m; j++) {
            if (i == x && j == y) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }


    zero_dp = dp[n][m]; //차이 구하기
    if (cur_dp_count == zero_dp) {
        cout << dp[n][m];
        return 0;
    }
    else {
        cout << cur_dp_count - zero_dp;
        return 0;
    }


}
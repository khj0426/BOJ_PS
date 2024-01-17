#include <iostream>

using namespace std;

int arr[301][301];
int dp[301][301];

//arr[1][1] ~ arr[2][3]

// 1 3 7
// 9 31 63


//2차원 배열에서의 누적합

// dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j]
int main(void){
    int n,m;
    cin >> n >> m;


    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> arr[i][j];
        
            if(i == 1 && j == 1 ){
                
                dp[i][j] = arr[i][j];
                
            }
            else{
                dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
              

        }
    }
    }

    int k;
    cin >> k;

    for(int i = 0;i<k;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
    }


    
    }
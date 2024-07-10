#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100000][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i = 0;i<land.size();i++){
        for(int j = 0;j<land[i].size();j++){
            if(i == 0){
                dp[i][j] = land[i][j];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i = 0;i<land.size();i++){
        for(int j = 0;j<4;j++){
            if(j == 0){
                dp[i][j] = land[i][j] + dp[i-1][1];
                int sec = land[i][j] + dp[i-1][2];
                int third = land[i][j] + dp[i-1][3];
                
                int max_ = max(sec,third);
                dp[i][j] = max(max_,dp[i][j]);
                
            }
            else if(j == 3){
                dp[i][j] = land[i][j] + dp[i-1][2];
                int z = land[i][j] + dp[i-1][0];
                int f = land[i][j] + dp[i-1][1];
                int max_ = max(z,f);
                dp[i][j] = max(dp[i][j],max_);
            }
            else{
                int prev = land[i][j] + dp[i-1][j-1];
                int next = land[i][j] + dp[i-1][j+1];
                int prev_first = land[i][j] + dp[i-1][0];
                int prev_next = land[i][j] + dp[i-1][3];
                int max_ = max(prev_first,prev_next);
                dp[i][j] = max(prev,next);
                dp[i][j] = max(dp[i][j],max_);
                
            }
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    answer = -987654321;
   for(int i = 0;i<land.size();i++){
       for(int j = 0;j<4;j++){
           if(dp[i][j] > answer){
               answer  = dp[i][j];
           }
       }
       cout << '\n';
   }

    return answer;
}
#include <iostream>
#include <algorithm>
using namespace std;
 
char map[5][5];
int dp[5][5];
int dp_min[5][5];
int n;
 
void init(){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
}
 
void solve(){
    dp[0][0] = map[0][0] - 48;
    dp_min[0][0] = dp[0][0];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i == 0 && j == 0){
               continue;
            }
            int first,second,first_min,second_min;
            if(i == 0){
                if(map[i][j] >= '0' && map[i][j] <= '5'){
                    if(map[i][j-1] == '+'){
                        first = dp[i][j-2] + (map[i][j]-48);
                    }
                    if(map[i][j-1] == '-'){
                        first = dp[i][j-2] - (map[i][j] - 48);
                    }
                    if(map[i][j-1] == '*'){
                        first = dp[i][j-2] * (map[i][j] - 48);
                    }
                    dp[i][j] = first;
                    dp_min[i][j] = first;
                }
            }
            else if(j == 0){
                if(map[i][j] >= '0' && map[i][j] <= '5'){
                    if(map[i-1][j] == '+'){
                        first = dp[i-2][j] + (map[i][j]-48);
                    }
                    if(map[i-1][j] == '-'){
                        first = dp[i-2][j] - (map[i][j]-48);
                    }
                    if(map[i-1][j] == '*'){
                        first = dp[i-2][j] * (map[i][j]-48);
                    }
                    dp[i][j] = first;
                    dp_min[i][j] = first;
                }
            }
            else{
                if(map[i][j] >= '0' && map[i][j] <= '5'){
                    if(map[i-1][j] == '+'){
                        int temp1 = dp[i-2][j] + (map[i][j]-48);
                        int temp2 = dp[i-1][j-1] + (map[i][j] - 48);
                        first = max(temp1,temp2);
                        int temp3 = dp_min[i-2][j] + (map[i][j]-48);
                        int temp4 = dp_min[i-1][j-1] + (map[i][j]-48);
                        first_min = min(temp3,temp4);
                        if(i-2 < 0){
                            first = temp2;
                            first_min = temp4;
                        }

                    }
                    if(map[i-1][j] == '-'){
                        int temp1 = dp[i-2][j] - (map[i][j]-48);
                        int temp2 = dp[i-1][j-1] - (map[i][j]-48);
                        int temp3 = dp_min[i-2][j] - (map[i][j]-48);
                        int temp4 = dp_min[i-1][j-1] - (map[i][j]-48);
                        first_min = min(temp3,temp4);
                        first = max(temp1,temp2);
                          if(i-2 < 0){
                            first = temp2;
                            first_min = temp4;
                        }
                    }
                    if(map[i-1][j] == '*'){
                        int temp1 = dp[i-2][j] * (map[i][j]-48);
                        int temp2 = dp[i-1][j-1] * (map[i][j]-48);
                        int temp3 = dp_min[i-2][j] * (map[i][j]-48);
                        int temp4 = dp_min[i-1][j-1] * (map[i][j]-48);
                        first = max(temp1,temp2);
                        first_min = min(temp3,temp4);
                          if(i-2 < 0){
                            first = temp2;
                            first_min = temp4;
                        }
                    }
                    if(map[i][j-1] == '+'){
                        int temp1 = dp[i][j-2] + (map[i][j]-48);
                        int temp2 = dp[i-1][j-1] + (map[i][j]-48);
                        int temp3 = dp_min[i][j-2] + (map[i][j]-48);
                        int temp4 = dp_min[i-1][j-1] + (map[i][j]-48);
                        second = max(temp1,temp2);
                        second_min = min(temp3,temp4);
                        if(j-2 < 0){
                            second = temp2;
                            second_min = temp4;
                        }
                    }
                    if(map[i][j-1] == '-'){
                        int temp1 = dp[i][j-2] - (map[i][j]-48);
                        int temp2 = dp[i-1][j-1] - (map[i][j]-48);
                        int temp3 = dp_min[i][j-2] - (map[i][j]-48);
                        int temp4 = dp_min[i-1][j-1] - (map[i][j]-48);
                        second = max(temp1,temp2);
                        second_min = min(temp3,temp4);
                        if(j-2 < 0){
                            second = temp2;
                            second_min = temp4;
                        }
                    }
                    if(map[i][j-1] == '*'){
                        int temp1 = dp[i][j-2] * (map[i][j]-48);
                        int temp2 = dp[i-1][j-1] * (map[i][j]-48);
                        int temp3 = dp_min[i][j-2] * (map[i][j]-48);
                        int temp4 = dp_min[i-1][j-1] * (map[i][j]-48);
                        second = max(temp1,temp2);
                        second_min = min(temp3,temp4);
                        if(j-2 < 0){
                            second = temp2;
                            second_min = temp4;
                        }
                    }
                    dp[i][j] = max(first,second);
                    dp_min[i][j] = min(first_min,second_min);
 
 
                }
            }
 
        }
    }
}
int main(void){
    init();
    solve();
    cout << dp[n-1][n-1] << ' ' << dp_min[n-1][n-1];
}
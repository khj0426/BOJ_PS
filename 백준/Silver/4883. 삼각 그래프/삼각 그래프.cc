#include <iostream>
using namespace std;
typedef long long ll;

ll min(ll a,ll b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int main(void){
    int first = 1;
    
    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        ll dp[100001][3];
        int arr[100001][3];
        
        for(int i = 0;i<n;i++){
           for(int j = 0;j<3;j++){
               cin >> arr[i][j];
              
           }
        }
        
        
        dp[0][0] = 987654321;
        
        dp[0][1] = arr[0][1];
        dp[0][2] = dp[0][1] + arr[0][2];
        
        
 
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<3;j++){
               if(j == 0){
                   dp[i][j] = min(dp[i-1][j] + arr[i][j],dp[i-1][j+1] + arr[i][j]);
               }
               else if(j == 1){
                   ll first_path = dp[i][j-1] + arr[i][j];
                   ll second_path = dp[i-1][j-1] + arr[i][j];
                   ll third_path = dp[i-1][j] + arr[i][j];
                   ll last_path = dp[i-1][j+1] + arr[i][j];
                   ll temp = min(first_path,second_path);
                   dp[i][j] = min(last_path,(min(temp,third_path)));
               }
               else if(j == 2){
                   ll first_path = dp[i-1][j] + arr[i][j];
                   ll second_path = dp[i-1][j-1] + arr[i][j];
                   ll third_path = dp[i][j-1] + arr[i][j];
                   dp[i][j] = min(third_path,min(first_path,second_path));
               }
            }
        }
        
     
            cout << first << '.' << ' ' << dp[n-1][1] << '\n';
            first++;
    }
}
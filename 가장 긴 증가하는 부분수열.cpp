#include <iostream>
using namespace std;

//백준 LIS(O(n^2))

int main(void){
    int arr[1010];
    int dp[1010];
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[i] > arr[j] && dp[j]+1 > dp[i]){
                dp[i] = dp[j] + 1;
            } 
        }
    }
    
    int max_lis = 0;
    for(int i = 0;i<n;i++){
        if(dp[i] > max_lis){
            max_lis = dp[i];
        }
    }
    cout << max_lis;
}
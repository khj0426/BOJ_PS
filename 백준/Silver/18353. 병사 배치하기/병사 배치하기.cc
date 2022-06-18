#include <iostream>
using namespace std;
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    int n;
    cin >> n;
    int arr[2000];
    int dp[2000];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    
    int max = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[i] < arr[j] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    for(int i = 0;i<n;i++){
        if(dp[i] > max){
            max = dp[i];
        }
    }
    
    cout << n-max;
}
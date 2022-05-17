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
 
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    int arr[3];
    int dp[3];
    int mdp[3];
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[0] >> arr[1] >> arr[2];
        int temp_one = dp[0];
        int temp_two = dp[1];
        int temp_three = dp[2];
 
        int mdp_one = mdp[0];
        int mdp_two = mdp[1];
        int mdp_three = mdp[2];
 
        if(i == 0){
            dp[0] = arr[0];
            dp[1] = arr[1];
            dp[2] = arr[2];
            mdp[0] = arr[0];
            mdp[1] = arr[1];
            mdp[2] = arr[2];
 
        }
        else{
            dp[0] = max(dp[0] + arr[0],dp[1] + arr[0]);
            int big = max(temp_one+arr[1],temp_three+arr[1]);
            dp[1] = max(big,temp_two + arr[1]);
            dp[2] = max(temp_two + arr[2],temp_three + arr[2]);
 
            mdp[0] = min(mdp_one + arr[0],mdp_two + arr[0]);
            int small = min(mdp_one+arr[1],mdp_two+arr[1]);
            mdp[1] = min(small,mdp_three + arr[1]);
            mdp[2] = min(mdp_two + arr[2], mdp_three + arr[2]);
        }

    }
 
    cout << max(max(dp[0],dp[1]),dp[2]) << ' ';
    cout << min(min(mdp[0],mdp[1]),mdp[2]);
 
}
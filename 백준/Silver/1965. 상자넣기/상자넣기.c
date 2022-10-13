#include <stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
 
 
 
int main(void){
    int array[1005];
    int dp[1005];
 
 
    int n;
    scanf("%d",&n);
 
    for(int i = 0;i<n;i++){
        scanf("%d",&array[i]);
        dp[i]= 1;
    }
 
 
 
    int min = -1;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(array[i] > array[j]){
               dp[i] = max(dp[i],dp[j]+1);
            }
 
 
            }
        if(dp[i] > min){
            min = dp[i];
        }
 
 
        }
 
printf("%d",min);
}
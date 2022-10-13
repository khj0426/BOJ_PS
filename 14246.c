#include <stdio.h>

//백준 14246 
int main(void){
    int n;
    scanf("%d",&n);
 
 
   long long count = 0;
    int arr[100010];
    int arr_sum = 0;
 
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
        arr_sum = arr_sum + arr[i];
    }
 
    long long m;
    scanf("%lld",&m);
 
    int l = 0;
    int r = 0;
 
    
    for(l = 0;l<n;l++){
          long long sum  = 0;
        for(r = l;r<n;r++){
            sum = sum + arr[r];
            if(sum > m){
                count = count + (n-r);
                break;
            }
        }
    }
 
 printf("%lld",count);
}
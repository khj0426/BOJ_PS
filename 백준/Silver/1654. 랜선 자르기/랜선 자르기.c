#include <stdio.h>
#include <stdlib.h>
long long compare(const void *a,const void *b){
long long num1 = *(long long *)a;
long long num2 = *(long long *)b;
if(num1 > num2){
    return 1;
}
else if(num1 < num2){
    return -1;
}
else{
    return 0;
}}
 
int main(void){
    long long n;
    long long k;
    scanf("%lld %lld",&n,&k);
    
    long long arr[10000];
    for(int i = 0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    
    qsort(arr,n,sizeof(long long),compare);
    
    long long l = 1;
    long long r = arr[n-1];
    long long min = -1;
    
    while(l<=r){
        long long sum = 0;
        long long mid = (l+r)/2;
        for(int i = 0;i<n;i++){
            sum = sum + arr[i]/mid;
        }
        
        if(sum < k){
            r = mid - 1;
        }
        else if(sum >= k){
            l = mid + 1;
            if(mid > min){
                min = mid;
            }
        }
    }
    printf("%lld",min);
}
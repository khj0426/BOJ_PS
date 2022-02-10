#include <stdio.h>
#include <stdlib.h>

//백준 나무 자르기(이진 탐색)

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
    }
}

int main(void){
    long long n;
    long long m;
    scanf("%lld %lld",&n,&m);
    
    long long arr[1000000];
    for(int i = 0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    
    qsort(arr,n,sizeof(long long),compare);
    
    long long min = -1;
    long long l = 0;
    long long r = arr[n-1];
    
    while(l<=r){
        long long mid = (l+r)/2;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] > mid){
                sum = sum + (arr[i]-mid);
            }
        }
        if(sum < m){
            r = mid - 1;
        }
        else{
            l = mid + 1;
            if(mid > min){
                min = mid;
            }
        }
    }
    printf("%lld",min);
}
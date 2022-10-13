#include <stdio.h>
#include <stdlib.h>

//백준 1654 랜선자르기 (이진탐색)
/* 1)처음 랜선들을 입력받고 랜선들을 오름차순 정렬 (배열의 마지막원소 == 가장 긴 랜선)
   2)mid값을 정하고 (이 떄 l->1로 둔다) l->0일 경우 divisionbyzero 에러 발생
   
       입력이
       2 2

        1

        1 
    일때 mid = (0 + 1)/2 -> 0이고 arr[i]/mid 를 할떄 0으로 나뉘어지기 떄문에.
    
    3)for문을 돌리면서 배열의 랜선을 mid로 나눈 값을 더해나간다
    
    4)for문을 돌리고 더해나간 값(sum값)이 N개의 랜선보다 작다면 mid값을 줄여야 하므로 r = mid - 1
    
    5)그 외 경우에는 mid값을 키워나가야 함->l = mid + 1
        */

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
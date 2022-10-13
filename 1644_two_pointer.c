#include <stdio.h>
#include <stdlib.h>
#define size 4000000

//백준 1644 소수의 연속합

/* 소수를 에라토스테네스의 체로 거르고 소수들을 따로 배열에 담아둔다
   그 후 투포인터 사용(l과 r이 같으면 같은 소수를 가르키므로 l<r조건 필요)
   
   합이 N보다 크거나 같은 경우
   )합이 N인경우 ->count 증가 + 합에서 배열의 l값 뺴주고 l++
   
   합이 N보다 큰 경우 -> 합에서 배열의 l값 뺴주고 l++
   
   합이 N보다 작은 경우->r증가 + 합에다가 배열의 r값 더해준다
   
   */

 
int arr[size];
int Primes[size];
 
 
 
void Prime_num(int n){
   int idx = 0; 
    for(int i = 2;i<=n;i++){
        arr[i] = i;
    }
 
    for(int i = 2;i<=n;i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = i+i;j<=n;j=j+i){
            arr[j] = 0;
        }
    }
 
    for(int i = 2;i<=n;i++){
        if(arr[i] != 0){
            Primes[idx] = arr[i];
            idx++;
        }
    }
}
 
int main(void){
    int n;
    scanf("%d",&n);
 
    Prime_num(n);
 
    int count = 0;
 
    int l = 0;
    int r = 0;
    long long sum = Primes[0];
 
 
    while(r<n){
         if(sum == n){
             count++;
             sum = sum - Primes[l];
             l++;
         }    
        else if(sum < n){
            r++;
            sum = sum + Primes[r];
        }
        else if(sum > n){
            sum = sum - Primes[l];
            l++;
        }
    }
    if(n == 1 || count == 0){
    	printf("0");
    }
 
    else{
    printf("%d",count);
}
}
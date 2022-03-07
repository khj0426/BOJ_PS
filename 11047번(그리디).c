#include <stdio.h>
#include <stdlib.h>
//백준 11047 동전 0

int compare(const void *a,const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if(num1 > num2){
        return -1;
    }
    else if(num1 < num2){
        return 1;
    }
    else{
        return 0;
    }
}
int main(void){
    int arr[11];

    int n;
    long long k;
    scanf("%d",&n);
    scanf("%lld",&k);

    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(int),compare);

    long long sum = 0;
    int idx = 0;
    int count = 0;
   long long temp = 0;

 for(int i = 0;i<n;i++){
     temp = k;
     if(k == 0){
         break;
     }

         count = count + (k/arr[i]);

         k = k % arr[i];

 }
  printf("%d\n",count);
} 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//백준 2012번


int compare(const void *a,const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
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
    int arr[500001];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    qsort(arr,n,sizeof(int),compare);
    
long long sum = 0;
    
    for(int i = 1;i<=n;i++){
    sum = sum + abs(i-arr[i-1]);    
    }
    printf("%lld",sum);
}
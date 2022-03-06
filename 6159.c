#include <stdio.h>
#include <stdlib.h>
 //백준 6159번

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
    int n;
    int s;
    int arr[20000];
    scanf("%d %d",&n,&s);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
 
    qsort(arr,n,sizeof(int),compare);
 
    int l = 0;
    int r = n-1;
    long long sum = 0;
    int count = 0;
 
     for(l = 0;l<n;l++){
         r = l+1;
         while(r<n){
             sum = arr[l]+arr[r];
             if(sum <= s){
                 count++;
             }
            r++;
         }
 
     }
    printf("%d",count);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
long long compare(const void *a,const void *b){
   long long num1= *(long long *)a;
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
    long long arr[2001];
 long long n;
    scanf("%lld",&n);
 
    for(int i = 0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    qsort(arr,n,sizeof(long long),compare);
 
    int count = 0;
 
    for(int i = 0;i<n;i++){
         int l = 0;
         int r = n-1;
 
        while(l<r && r<n){
              long long sum = arr[l] + arr[r];
             if(sum > arr[i]){
                 r--;
             }
            else if(sum < arr[i]){
                l++;
            }
            else if(sum == arr[i]){
                if(l != i && r != i){
                 
                    count++;
                    break;
                }
                else if(l == i){
                    l++;
                }
                else if(r == i){
                    r--;
                }
                
             
            }
        }
    }
 printf("%d",count);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
bool is_empty[1000];
 
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
 
    int arr[100001];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
 
    }
 
    qsort(arr,n,sizeof(int),compare);
 
 
 
   for(int i = 0;i<n;i++){
       if(arr[i] != arr[i+1]){
           printf("%d ",arr[i]);
       }
   }
 
}
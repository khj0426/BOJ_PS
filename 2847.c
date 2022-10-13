#include <stdio.h>

//백준 2847번

int main(void){
    int arr[300];
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    
   
    
    int count = 0;
    
    for(int i = n;i>=1;i--){
       
        if(arr[i] <= arr[i-1]){
          int temp = arr[i] - 1;
            count = count + (arr[i-1] - temp);
            arr[i-1] = temp;
        }
    }
    
    printf("%d",count);
}
#include <stdio.h>
#include<stdbool.h>
#define Size 1000000
 
int main(void){
    long long sum = 1;
    int n;
    scanf("%d",&n);
  long long array[Size];
    bool arr[Size];
 
 
      for(int i = 2;i<=Size;i++){
        array[i] = i;
          arr[i] = false;
    }
    for(int i = 2;i<=Size;i++){
        if(array[i] == 0){
            continue;
        }
        for(int j = i+i;j<=Size;j=j+i){
            array[j] = 0;
        }
    }
 
 
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
 
        if(array[x] != 0 && arr[x] != true){
            sum = sum * array[x];
            arr[x] = true;
        }
    }
    if(sum == 1){
        printf("-1\n");
    }
    else{
        printf("%lld",sum);
    }
}
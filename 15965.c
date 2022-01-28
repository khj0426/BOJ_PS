#include <stdio.h>
 
int main(void){
    int array[7368788];
    for(int i = 2;i<=7368787;i++){
        array[i] = i;
    }
    int count = 0;
 
    for(int i = 2;i<=7368787;i++){
        if(array[i] == 0){
            continue;
        }
        for(int j = i+i;j<=7368787;j=j+i){
            array[j] = 0;
        }
    }
     int k;
    scanf("%d",&k);
 
    for(int i = 2;i<=7368787;i++){
       if(array[i] != 0){
           count = count + 1;
       }
        if(count == k){
            printf("%d",array[i]);
            break;
        }
    }
 
 
 
}
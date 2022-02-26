#include <stdio.h>
#include <string.h>

int main(void){
    char arr[100000];
    char sub_arr[100000];
    
    while(scanf("%s %s",sub_arr,arr)!= EOF){
        int idx = 0;
        for(int i = 0;i<strlen(arr);i++){
            if(arr[i] == sub_arr[idx]){    
                idx++;
            }
        }
        if(idx != strlen(sub_arr)){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
}
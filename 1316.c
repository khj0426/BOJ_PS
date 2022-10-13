#include <stdio.h>
#include <string.h>

//백준 1316
 
int main(void){
    int n;
    scanf("%d",&n);
    int count = 0;
 
    for(int i = 0;i<n;i++){
          int bool = 0;
        char arr[100];
        scanf("%s",arr);
        for(int i = 0;i<strlen(arr);i++){
            for(int j = i+1;j<strlen(arr);j++){
                if(arr[i] == arr[j]){
                    for(int k = i;k<j;k++){
                        if(arr[k] != arr[i] || arr[k] != arr[j]){
                            bool = 1;
                            break;
                        }
                    }
                }
                if(bool == 1){
                    break;
                }
            }
            if(bool == 1){
                break;
            }
        }
        if(bool == 0){
            count++;
        }
    }
    printf("%d",count);
}
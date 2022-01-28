#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int compare(const void *a,const void *b){
 
    char num1 = *(char *)a;
    char num2 = *(char *)b;
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
    char array[11];
    scanf("%s",&array);
 
 
    qsort(array,strlen(array),sizeof(char),compare);
 
    for(int i = 0;i<strlen(array);i++){
        printf("%c",array[i]);
    }
}
 
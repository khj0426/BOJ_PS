#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//백준 10610번 30의 배수가 되는 가장 큰 수 만들기

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
	int temp = 0;
 
    char arr[1000000]; 
    scanf("%s",arr);
 
    int sum = 0;
 
    for(int i = 0;i<strlen(arr);i++){ 
        sum = sum + arr[i]; 
        if(arr[i] == '0'){
        	temp = 1;
        }
    }
    int a = atoi(arr);
 
    if(sum % 3 == 0 && temp == 1){
       qsort(arr,strlen(arr),sizeof(char),compare);
       for(int i = 0;i<strlen(arr);i++){
       printf("%c",arr[i]);
   }
    }
    else if(sum % 3 != 0 || a % 10 != 0){
        printf("-1\n");
    }
 
 
}
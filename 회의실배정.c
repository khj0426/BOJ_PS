#include <stdio.h>
#include <stdlib.h>

//백준 회의실 배정 (끝나는 순서대로)
 
struct room{
    int start;
    int end;
};
 
int compare(const void *a,const void *b){
    struct room num1 = *(struct room *)a;
    struct room num2 = *(struct room *)b;
 
    if(num1.end > num2.end){
        return 2;
    }
    else if(num1.end <num2.end){
        return -2;
    }
    else{
        if(num1.start >num2.start){
            return 1;
        }
        else if(num1.start < num2.start){
            return -1;
        }
        else{
            return 0;
        }
    }
 
}
 
int main(void){
    struct room Arr[100000];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d %d",&Arr[i].start,&Arr[i].end);
    }
 
    qsort(Arr,n,sizeof(struct room),compare);
 
 
    int Max = 0;
    int count = 0;
 
   for(int i = 0;i<n;i++){
       if(i == 0){
       Max = Arr[i].end;
           count++;
   }
       else{
           if(Arr[i].start >= Max){
               Max = Arr[i].end;
               count++;
           }
       }
 
   }
 
    printf("%d",count);
}
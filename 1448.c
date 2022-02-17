#include <stdio.h>
int compare(const void *a,const void *b){ 
    int num1 = *(int *)a;
    int num2 = *(int *)b;
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
    int arr[1000010];
    int n;
    scanf("%d",&n);
 
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
 
    qsort(arr,n,sizeof(int),compare); //내림차순 정렬
 
   long long Max = 0;
    //삼각형의 최대값 반복문을 끝내도 Max가 0이면 삼각형이 성립 안되는 조건이므로 -1을 찍는다

 
    for(int i = 0;i<n;i++){
        int max = arr[i]; //max를 배열의 i값으로
        if(max < arr[i+1]+arr[i+2]){ //삼각형이 성립한다면
         Max = arr[i] + arr[i+1] + arr[i+2]; //삼각형 세 변의 길이의 값을 Max로 바꾸고
          break;//루프탈출
        }
    }
 
    if(Max != 0){
    printf("%lld",Max);
    }
    else{
        printf("-1");
    }
}
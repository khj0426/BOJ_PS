#include <stdio.h> //sprintf함수 사용 (정수 -> 문자열로)
#include <string.h> //strstr함수 사용(문자열에서 특정 문자열 찾는 함수)
 
int main(void){
    
   long long i = 666; //초기값 설정
    int count = 1; //초기값 설정 2
 
    char arr[5] = "666"; //666을 담은 배열
    char array[100000]; // 10000번째 종말의 수?
 
    int n;
    scanf("%d",&n); //n 입력받고
 
    while(1){
        i++; //i 1씩 증가
        sprintf(array,"%d",i); //정수를 문자열로 바꾸는 함수 (array에 정수인 i를 문자열로 바꾸고 넣기)
        if(strstr(array,arr) != NULL){ //strstr함수 (문자열에서 특정 문자열 찾는 함수)
            count++; //종말의 수면 count증가
        }
        if(n == count){ //n번쨰 종말의 수면 루프 탈출
            break;
        }
 
    }
 
 
    if(n == 1){
        printf("666\n");
    }
    else{
        printf("%lld",i);
    }
 
 
}
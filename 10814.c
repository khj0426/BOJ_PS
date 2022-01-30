#include <stdio.h>
#include <stdlib.h>
 
struct Info{ //회원정보의 대한 구조체 선언
    int age; //회원의 나이
    char arr[101]; //회원의 이름
};
 
int compare(const void *a,const void *b){ //compare함수
  
    //기존의 int -> struct Info로 바꿈
    //나이가 많은 순으로
    
   struct Info num1 = *(struct Info *)a; 
    struct Info num2 = *(struct Info *)b;
 
    if(num1.age > num2.age){ 
        return 1;    
    }
    else if(num1.age < num2.age){
        return -1;
    }
    else{
        return 0;
    }
 
}
 
int main(void){
    
    struct Info array[100000]; //회원정보의 대한 배열
    
    int n;
    scanf("%d",&n);
 
    for(int i = 0;i<n;i++){
        scanf("%d %s",&array[i].age,&array[i].arr); //회원의 나이와 회원의 이름을 입력받습니다.
    }
 
    qsort(array,n,sizeof(struct Info),compare); //qsort함수 
    
    //회원의 나이가 적은 순대로 오름차순 정렬
 
    for(int i = 0;i<n;i++){
      printf("%d %s\n",array[i].age,array[i].arr); //회원정보 출력하기
 
    }
}
 
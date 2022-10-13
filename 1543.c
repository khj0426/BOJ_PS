#include <stdio.h>
#include <string.h>

/*백준 1543(문자열)

   방법 -> 1)문서의 길이만큼 루프를 돌린다
   
          2)단어의 길이만큼 임시 temp배열에 문서를 넣는다
          
          3)만역 temp배열과 sub_arr(단어)가 일치한다면 count증가 (이때 i도 단어의 길이-1만큼 이동한다)
          
          4)만악 temp배열과 sub_arr(단어)가 일치하지 않는다면 루프 계속 continue
          */
 
int main(void){
    char arr[2500];
    char sub_arr[50];
 
    gets(arr);
    gets(sub_arr);
 
    int count = 0;
    int idx = 0;
 
 
 
   for(int i = 0;i<strlen(arr);i++){
       char temp[50];
 
       for(int j = 0;j<strlen(sub_arr);j++){
           temp[j] = arr[i+j];
       }
 
       if(strcmp(temp,sub_arr) == 0){
           i = i + strlen(sub_arr)-1;
           count++;
       }
       else if(strcmp(temp,sub_arr) != 0){
           continue;
       }
 
 
   }
    printf("%d",count);
 
}
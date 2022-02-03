#include <stdio.h>

int main(void){
    int n;
    int m;
    scanf("%d %d",&n,&m);
    
    int arr[10000];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   
    int count = 0;
    for(int i = 0;i<n;i++){
         int sum = 0;

         /*반복문에서 sum을 0으로 초기화 해야 함

         ex 배열이
         1 2 3 4 5 이고 m이 5라면

         1,2,3,4,5에 대해서 합이 0인 상태로 시작해야 한다.
         합을 0으로 초기화를 안한다면 -> 합이 m보다 커지기 떄문
         */
        for(int j = i;j<n;j++){
            sum = sum + arr[j]; //합을 더해가면서
            if(sum == m){ //합이 m이라면
                count++; //count증가 후 break문을 통해 루프 탈출
                break;
            }
        }
    }
    printf("%d",count);
}
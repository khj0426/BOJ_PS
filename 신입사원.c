#include <stdio.h>
#include <stdlib.h> 

//백준 신입사원
/* 1)qsort로 1차 서류심사순으로 오름차순 정렬.
   2)n번만큼 루프 돌리면서 서류심사 , 면접시험이 모두 큰 경우를 제외하고 인원 수 증가
   3)min값을 현재 i번째 점수로 바꿔줌
   */

struct score{ //점수를 나타내는 구조체
    int first_score; //서류심사
    int second_score; //면접심사
};
 
int compare(const void *a,const void *b){ //오름차순정렬
    struct score num1 = *(struct score *)a;
    struct score num2 = *(struct score *)b;
    if(num1.first_score > num2.first_score){
        return 1;
    }
    else if(num1.first_score < num2.first_score){
        return -1;
    }
    else{
        return 0;
    }
}
 
int main(void){
    int t;
    scanf("%d",&t);
 
    for(int i = 0;i<t;i++){
 
        struct score arr[100000]; 
 
        int n;
        scanf("%d",&n);
 
        for(int j = 0;j<n;j++){ //점수 입력받고
            scanf("%d %d",&arr[j].first_score,&arr[j].second_score);
 
        }
 
        qsort(arr,n,sizeof(struct score),compare); //정렬
 
          int cnt = 0;//최대 인원수 변수
        
          struct score min;//점수의 최소값 -> 루프마다 바뀐다
        
          for(int k = 0;k<n;k++){ //n번 돌면서
        if( arr[k].first_score > min.first_score && arr[k].second_score > min.second_score){
           continue; //서류와 면접이 모두 높은 경우 continue
          }
            else{ //그 외의 경우 cnt++
                cnt++;
            }
            min = arr[k]; //최소값을 현재 점수로 바꿔준다
 
        }
        printf("%d\n",cnt);
    }
 
 
}
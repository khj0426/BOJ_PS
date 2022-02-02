#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 //백준 2467 용액
 //투포인터 문제

int main(void){
    
   long long arr[100000]; //용액 담을 배열
    int n;
    scanf("%d",&n);
 
    for(int i = 0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    
    int l = 0; //왼쪽 끝
    int r = n-1; //오른쪽 끝
    
    long long min =  2000000001; //변수 초기화
    
   long long min_l = 0;  //특성값이 0에 가까운 용액의 왼쪽 값 
    long long min_r = 0; //특정값이 0에 가까운 용액의 오른쪽 값
 
    while(l<r && r<n){ //l<r l과 r이 같으면 같은 용액을 2번 가르키므로 l<r
        
        int sum = arr[l] + arr[r]; //두 용액의 합
        
       if(sum == 0){ //합이 0이면 특성값 == 0이므로 바로 루프 탈출
            min_l = arr[l]; 
            min_r = arr[r];
            break;
        }
        
        else if(sum > 0){ //합이 >0 이고
            if(abs(sum) < min){ //합의 절대값이 min보다 작다면
                min = sum; //min은 sum으로 갱신
                min_l = arr[l];
                min_r = arr[r];
            }
            r--; //용액이 오름차순 정렬되어 있는 상태니깐 오른쪽 끝을 줄인다.
            
          /*ex) -2 -1 0 1 2 5 일떄 처음 sum값은 3이고 sum > 0이므로 오른쪽 포인터를 줄이면
          sum값은 0이므로 sum > 0일때 오른쪽 포인터 감소시킴*/
        }
        else if(sum < 0){ //합이 <0 이고
            if(abs(sum) < min){ //합의 절대값이 min보다 작다면
                min = abs(sum); //min은 절대값 sum으로 갱신.
                min_l = arr[l];
                min_r = arr[r];
            }
            l++; //sum > 0과는 반대로 왼쪽 포인터 증가시킨다.
        }
        
    }
           printf("%lld %lld",min_l,min_r);
 
    }
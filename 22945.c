#include <stdio.h>
#include <stdlib.h>

//백준 22945번 개발자의 수와 개발자의 능력이 주어지고 팀 능력치의 최대값 구하기(이 떄 팀은 2명)

/* 팀 능력치 = Min(개발자1,개발자2) * (개발자1과 개발자2 사이의 사람 수)
    
   투포인터의 시작점을 배열의 처음과 끝으로 둔다.(이 떄 개발자의 능력의 최대값(min)을 0으로 초기화)
   팀 능력치가 min보다 크면 갱신


   l값이 증가하든 r값이 감소하든 개발자1과 개발자2 사이 사람 수는 무조건! 감소하게 된다.
   
   ->그러므로 Min(개발자1,개발자2)값을 최대로 해야함
   
   left,right포인터 중 값이 작은 포인터를 이동시켜야 Min값을 최대로 할 수 있다.
   
   
   만약 개발자1의 능력 < 개발자2의 능력 일 경우
   
   값이 개발자2보다 작은 개발자1의 포인터를 오른쪽으로 이동시킨다.
   
   l++ 
   
   그렇지 않을 경우
   
   개발자2의 포인터를 왼쪽으로 이동시킨다.
   
   r--
   
   */

int Min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}


int main(void){
    
    int arr[100000];
    
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int l = 0;
    int r = n-1;
    
    int min = 0;
    
    qsort(arr,n,sizeof(int),compare);
    
    while(l<r){
        int ability = Min(arr[l],arr[r]) * (r-l -1);
        if(ability > min){
            min = ability;
        }
        
        if(arr[l] < arr[r]){
            l++;
        }
        else{
            r--;
        }
        
    }
    printf("%d",min);
    
}

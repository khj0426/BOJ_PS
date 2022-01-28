#include <stdio.h>
//백준 4948번
//n보다 크고 2n보다 작은 소수 개수 출력하는 프로그램
 
int Prime_num(int n){ //n이 주어젔을떄
    int m = n*2; //m = 2n이고
    int count = 0; //개수 0으로 초기화
 
    int array[1000001];
    if(n == 1){
    	return 1; //n이 1이면 1 리턴
    }
 
    for(int i = 2;i<=m;i++){ //2부터 m까지 배열에 넣고
        array[i] = i;
    }
 
    for(int i = 2;i<=m;i++){ //소수가 아닌 값 0으로 만들고
        if(array[i] == 0){
            continue;
        }
        for(int j = i+i;j<=m;j = i+j){
            array[j] = 0;
        }
    }
 
    for(int i = n+1;i<=m;i++){ //m까지 소수이면 count값 증가
        if(array[i] != 0){
            count++;
        }
    }
 
    return count;
}
int main(void){
 
 while(1){
     int x;
     scanf("%d",&x);
     if(x == 0){
         break;
     }
    else if(x == 1){
    	printf("1\n");
    }
     else{
         printf("%d\n",Prime_num(x));
     }
 }
 
}
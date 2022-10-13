#include <stdio.h>

//백준 1629 분할정복
/* X를 A Y를 B로 둔다 (X를 Y번 곱한다.)

  Y == 1 일때 X를 1번 곱하므로 X 그 자체를 리턴
  Y == 0일때 X를 0번 곱하므로 1리턴
  
  Y가 홀수일떄 -> Pow(X,Y-1) * X
  
  Y가 짝수일떄 ->Pow(X,Y) ->  Pow(X,2/Y) * Pow(X,2/Y)
  
  값을 계산할 떄 C로 나머지 연산을 해준다.
  
  */
long long a,b,c;

long long Pow(long long x,long long y){
    if(y == 0){
        return 1;
    }
    else if(y == 1){
        return x;
    }
    else if(y % 2 != 0){
        return Pow(x,y-1)*x;
    }
    else{
        long long half = (Pow(x,y/2))%c;
        return (half*half)%c;
    }
}

int main(void){
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld",Pow(a,b)%c);
}
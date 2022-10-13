#include <stdio.h>
#include <math.h>
#define LEN 100000000 
//백준 14905번

int array[LEN];
int Lprime = 0; 
int Rprime = 0;
 
void Push(){ //에라토스테네스의 체로 소수 판별
 
    for(int i = 2;i<=sqrt(LEN);i++){
        array[i] = i;
    }
    for(int i = 2;i<=LEN;i++){
        if(array[i] == 0){
            continue;
        }
        for(int j = i+i;j<=LEN;j=j+i){
            array[j] = 0;
        }
    }
}
 
int Prime_Calculate(int n){
 
    Lprime = 0;
    Rprime = 0;
 
    if(n<8){
        return -1; //8보다 작으면 -1리턴
    }
 
   else if(n%2 == 0){ //짝수일때  n = 2 + 2 + a + b의 형태로 나타낼 수 있어서 n-4 = a + b, n을 -4 하고 골드바흐의 추측으로 합이 n이 되는 소수를 찾자
      int N = n-4;
       for(int i = N/2;i>=2;i--){
           if(array[i] + array[N-i] == N){
               Lprime = array[i];
               Rprime = array[N-i];
               return 2; //짝수일때 2리턴
           }
       }
   }
    else if(n%2 != 0){//홀수일때 n = 2 + 3 + a + b의 형태로 표현가능하다. n-5 = a+b, n을 -5하고 골드바흐의 추측으로 합이 n이되는 소수를 찾자
        int N = n-5;
        for(int i = N/2;i>=2;i--){
            if(array[i] + array[N-i] == N){
                Lprime = array[i];
                Rprime = array[N-i];
                return 3; //홀수일때 3리턴
            }
        }
    }
    return -1;//그 외에는 -1리턴
}
 
int main(void){
 
    Push();
   int x;
    while(scanf("%d",&x)!= EOF){ //x가 EOF가 아닐때까지
 
        
        if(Prime_Calculate(x) == -1){ //-1이면 소수 4개의 합으로 나타낼 수 없다->Impossible출력
            printf("Impossible.\n");
        }
        else{ //2이면 짝수인경우
           if(Prime_Calculate(x) == 2){
             printf("2 2 %d %d\n",Lprime,Rprime);
           }
            else if(Prime_Calculate(x) == 3){ //3이면 홀수인 경우
                printf("2 3 %d %d\n",Lprime,Rprime);
            }
        }
      
 
 
    }
}
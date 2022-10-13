#include <stdio.h>

//1번쨰 주유소까지는 쭉 가고 2번쨰부터 ~ 만약 min기름보다 작다면 바꿔주기

int main(void){
    long long distance[100020];
    long long price[100020];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++){
        scanf("%lld",&distance[i]);
    }
    
    for(int i = 0;i<n;i++){
        scanf("%lld",&price[i]);
    }
    
    long long sum = 0;
    long long min = 1000000010;
    
    for(int i = 0;i<n-1;i++){
        if(i == 0){
            sum = sum + (price[i]*distance[i]);
            min = price[i];
        }
        else{
            if(price[i]<min){
                min = price[i];
            }
            sum = sum + min*distance[i];
        }
    }
    printf("%lld",sum);
}
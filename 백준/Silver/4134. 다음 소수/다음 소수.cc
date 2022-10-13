#include <iostream>
using namespace std;

typedef long long ll;

ll check(ll num){
    if(num == 0){
        return 2;
    }
    else if(num == 1){
        return 2;
    }
    for(ll i = num;i*i<=num;i++){
        bool valid = false;
       for(ll j = 2;j*j<=i;j++){
           if(i % j == 0){
               valid = true;
               break;
           }
       }
        if(valid == false){
           return i;
        }
    }
}

int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%ld",&n);
        printf("%ld \n",check(n));
    }
}
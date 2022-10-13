#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
 
ll calculate(ll a,ll x){
    if(x == 0){
        return 1;
    }
    else if(x == 1){
        return a;
    }
    else if(x%2 != 0){
        return calculate(a,x-1) % MOD * a % MOD;
    }
    else if(x%2 == 0){
        return calculate(a,x/2) % MOD * calculate(a,x/2) % MOD;
    }
}
int main(void){
    ll A;
    ll X;
    cin >> A >> X;
    cout << calculate(A % MOD,X) % MOD;
}
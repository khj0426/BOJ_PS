#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

//A^P % P == A (P가 소수가 아니면 가짜소수)
ll mod;

ll max(ll a,ll b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
    
}

ll min(ll a,ll b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
    
}

ll check_prime(ll num){ 
    //소수 최적화(루트 num까지 확인) 
    
    for(int i = 2;i*i <= num;i++){
        if(num%i == 0){
            return -1;
        }
    }
    return 1;
}

ll dfs(ll a,ll p){
    if(p == 0){
        return 1;
    }
    else if(p == 1){
        return a;
    }
    else if(p%2 == 0){
        return (dfs(a,p/2) % mod * dfs(a,p/2) % mod) % mod;
    }
    else if(p%2 != 0){
        return (a * dfs(a,p-1) % mod) % mod;
    }
}



int main(void){
    while(1){
        ll a,p;
        cin >> p >> a;
        
        if(a == 0 && p == 0){
            return 0;
        }
        p = max(a,p);
        a = min(a,p);
        
        mod = p;
        ll check_ = check_prime(p);
        if(check_== 1){
            cout << "no" << '\n';
            continue;
        }
        
       if(dfs(a,p) == a){
           cout << "yes" << '\n';
       }
        else{
            cout << "no" << '\n';
        }

    }
}

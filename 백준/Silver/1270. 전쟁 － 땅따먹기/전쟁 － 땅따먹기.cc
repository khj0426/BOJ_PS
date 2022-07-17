#include <iostream>
#include <string>
#include <map>
typedef long long ll;

using namespace std;
int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
   while(t--){
       ll n;
       cin >> n;
       ll ans = -1;
       ll count = -1;
       map<ll,ll> m;
       for(int i = 0;i<n;i++){
           ll x;
           cin >> x;
           ll temp = ++m[x];
           if(temp > ans){
               ans = temp;
               count = x;
           }
       }
       if(ans > n/2){
           cout << count << '\n';
       }
       else{
           cout << "SYJKGW" << '\n';
       }
   }

}
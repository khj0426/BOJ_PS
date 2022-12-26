#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
 
int main(void){
     cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll arr[1000001];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        ll l = 0;
        ll r = n-1;
        ll ans = 0;
        ll min_diff = arr[l] + arr[r];
        while(l<r && r < n){
            ll sum = arr[l] + arr[r];
 
            if(sum < k){
                l++;
            }
            else if(sum >= k){
                r--;
            }
 
            if(llabs(min_diff - k) > llabs(sum - k)){
                ans = 1;
                min_diff = sum;
            }
            else if(llabs(min_diff - k) == llabs(sum - k)){
                ans += 1;
            }
        }
 
        cout << ans << '\n';
    }
}
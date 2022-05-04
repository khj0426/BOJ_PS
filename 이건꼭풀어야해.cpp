#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

//백준 17390 이건 꼭 풀어야 해!
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll arr[300001];
    ll sum[300001];
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
 
    sort(arr,arr+n);
 
    for(int i = 0;i<n;i++){
        if(i == 0){
            sum[i] = arr[i];
        }
        else{
            sum[i] = sum[i-1] + arr[i];
        }
    }
 
  for(int i = 0;i<m;i++){
      int l,r;
      cin >> l >> r;
      if(l == r){
          cout << arr[l-1] << '\n';
      }
      else{
         cout << sum[r-1] - sum[l-2] << '\n';
      }
  }
 
}
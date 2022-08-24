#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void){
    ll n,l;
    cin >> n >> l;
    ll arr[1001];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        if(arr[i] <= l){
            l++;
        }
    }
    cout << l;
}
#include <iostream>
using namespace std;
//백준 13900 순서쌍의 곱의 합

typedef long long ll;
int main(void){
    ll arr[100001];
    ll sum[100001];
 
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        if(i == 0){
            sum[i] = arr[i];
        }
        else{
            sum[i] = arr[i] + sum[i-1];
        }       
    }
 
    long long total = 0;
    for(int i = 0;i<n-1;i++){
        total = total + arr[i] * (sum[n-1]-sum[i]);
    }
    cout << total;
 
}
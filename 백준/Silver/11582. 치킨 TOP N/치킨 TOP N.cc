#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
vector<ll> arr;
vector<ll> answer;
ll n;
ll k;
 
int main(void){
    cin >> n;
    for(ll i = 0;i<n;i++){
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    cin >> k;
    ll status = n;
 
 
    for(ll i = 2;i<=n;i=i*2){
        //01 01 01 01
        //0101 0101
        //01010101
        vector<ll> temp;
        ll count = 0;
        answer.clear();
        for(ll j = 0;j<n;j++){
            temp.push_back(arr[j]);
            count++;
 
            if(count == i){
                count = 0;
                sort(temp.begin(),temp.end());
                for(int k = 0;k<temp.size();k++){
                   answer.push_back(temp[k]);
                }
                temp.clear();
            }
 
        }
        if(i == n/k){
            for(int j = 0;j<answer.size();j++){
                cout << answer[j] << ' ';
 
            }
            return 0;
        }
        status++;
    }
}
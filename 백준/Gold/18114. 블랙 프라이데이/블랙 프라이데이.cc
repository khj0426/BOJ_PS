#include <iostream>
#include <algorithm>
 
 
using namespace std;
 
typedef long long ll;
int main(void){
    ll n,c;
    ll arr[5001];
 
    cin >> n >> c;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
 
    sort(arr,arr+n);
    bool is_able = false;
    for(int i = 0;i<n;i++){
       int l = i+1;
       int r = n-1;
       if(arr[i] == c || arr[l] == c || arr[r] == c){
           is_able = true;
           break;
       }
     
       while(l<=r){
           if(l == r){
               break;
           }
           ll sum = arr[i] + arr[l] + arr[r];
          
           if(sum == c || arr[i] == c || arr[l] == c || arr[r] == c || 
              sum-arr[l] == c || sum - arr[i] == c || sum - arr[r] == c){
               is_able = true;
               break;
           }
           
           if(sum < c){
               l++;
           }
           else if(sum > c){
               r--;
           }
       }
 
        if(is_able == true){
            break;
        }
 
    }
    if(is_able == true){
        cout << '1';
        return 0;
    }
    else if(is_able == false){
        cout << '0';
        return 0;
    }
 
}

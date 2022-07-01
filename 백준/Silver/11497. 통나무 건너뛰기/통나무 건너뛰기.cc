#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int arr[10001];
        int ans[10001];
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
 
      sort(arr,arr+n);
 
 
        int l = 0;
        int r = n-1;
        if(n%2 != 0){
            for(int i = 0;i<=n;i=i+2){         
                    ans[l] = arr[i];
                    ans[r] = arr[i+1];  
                    l++;
                    r--;
          }
            ans[n/2] = arr[n-1];
 
        }
 
        else if(n%2 == 0){
            for(int i = 0;i<n;i=i+2){
                ans[l] = arr[i];
                ans[r] = arr[i+1];
                l++;
                r--;
            }
        }
 
        int max = -1;
      for(int i = 1;i<n;i++){
          if(abs(ans[i] - ans[i-1]) > max){
              max = abs(ans[i] - ans[i-1]);
          }
      }
 
        if(abs(ans[0] - ans[n-1]) > max){
            max = abs(ans[0] - ans[n-1]);
        }
          cout << max << '\n';
 
 
    }
}
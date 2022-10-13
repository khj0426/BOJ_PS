#include <iostream>
using namespace std;
int main(void){
    int n;
    long long k;
    cin >> n >> k;
    
    int arr[100001];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i = 0;i<n;i++){
        k = k - arr[i];
        if(k < 0){
            cout << i+1;
            return 0;
        }
    }
    
    for(int i = n-1;i>=0;i--){
        k = k - arr[i];
        if(k < 0){
            cout << i+1;
            return 0;
        }
    }
}
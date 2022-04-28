#include <iostream>

//https://codeforces.com/contest/1635/problem/B

using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[10000001];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(i != 0 && i != n-1 && arr[i] > arr[i-1] && arr[i] > arr[i+1]){
 
              if(arr[i] >= arr[i+2]){
                   arr[i+1] = arr[i];
                   count++;
                   }
                   else if(arr[i] < arr[i+2]){
                       arr[i+1] = arr[i+2];
                       count++;
                   }
        }
        }
        cout << count << '\n';
        for(int i = 0;i<n;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
}

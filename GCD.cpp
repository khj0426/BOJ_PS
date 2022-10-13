#include <iostream>
#include <algorithm>
 
using namespace std;
//백준 9613 GCD합

int GCD(int a,int b){
        if(a%b == 0){
            return b;
        }
           int A= a;
           int B= b;
           int C= a%b;
        while(1){ 
            if(C== 0){
                return B;
            }
            else{
                A = B;
                B = C;
                C = A%B;
            }
 
 
        }
}
 
int main(void){
   int t;
   cin >> t;
    while(t--){
        long long count = 0;
        int arr[100];
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
 
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                    count = count + GCD(arr[i],arr[j]);      
            }
        }
        cout << count << '\n';
    }
}
#include <iostream>

//백준 21921 블로그 (슬라이딩 윈도우)

using namespace std;

int main(void){
    long long arr[250000];
    int n,k;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    long long sum = 0;
    long long max_length = 0;
    long long max = 0;
    
    for(int i = 0;i<k;i++){
        sum = sum + arr[i];
    }
    max = sum;
    max_length = 1;
    
    for(int i = k;i<n;i++){
        sum = sum + arr[i];
        sum = sum - arr[i-k];
        if(sum > max){
            max = sum;
            max_length = 1;
        }
        else if(sum == max){
            max_length++;
        }
    }
    
   if(max != 0){
   cout << max << '\n';
   cout << max_length << '\n';
   }
    else if(max == 0){
        cout << "SAD" << '\n';
    }
}
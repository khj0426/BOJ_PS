#include <iostream>

//백준 기상청 인턴 신현수 2435

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
using namespace std;
int main(void){
    int arr[100];
    int n;
    int k;
    cin >> n >> k;
    int min = -200000000;
    int sum = 0;
    for(int i = 0;i<n;i++){
    	cin >> arr[i];
    }
    for(int i = 0;i<k;i++){
        sum = sum + arr[i];
    }
    min = max(sum,min);
 
    for(int i = k;i<n;i++){
        sum = sum + arr[i];
        sum = sum - arr[i-k];
        min = max(sum,min);
    }
    cout << min;
}
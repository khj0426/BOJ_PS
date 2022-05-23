#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return b<a;
}
int main(void){
    int arr[100001];
    bool visited[100001] = {false, };
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,cmp);
 
    int sum = 0;
 
    for(int i = 0;i<n;i=i+3){
        for(int j = i;j<i+2;j++){
            if(j >= n){
                break;
            }
            sum = sum + arr[j];
        }
 
    }
 
 cout << sum;
 
 
}
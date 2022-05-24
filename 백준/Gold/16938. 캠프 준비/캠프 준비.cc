#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 15
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
 
int n,l,r,x;
vector<int> v;
int arr[15];
int cnt = 0;
int A[15];
 
 
void dfs(int start,int sum,int Max,int Min,int count){
     if(start == n){
         if(sum >= l && sum <= r && count >=1 && Max-Min >= x){
        cnt++;
    }
        return;
    }
    
 
    dfs(start+1,sum,Max,Min,count);
    dfs(start+1,sum+arr[start],max(Max,arr[start]),min(Min,arr[start]),count+1);
}
 
int main(void){
    cin >> n >> l >> r >> x;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    dfs(0,0,-987654321,987654321,0);
    cout << cnt;
}
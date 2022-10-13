#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

//백준 15970 화살표 그리기

using namespace std;
struct PAIR{
    int x;
    int color;
};
 
typedef struct PAIR p;
 
bool cmp(p a, p b){
    if(a.color != b.color){
        return a.color<b.color;
    }
    else if(a.color == b.color){
        if(a.x != b.x){
            return a.x<b.x;
        }
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
int main(void){
 
    p arr[5000];
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i].x >> arr[i].color;
    }
    sort(arr,arr+n,cmp);
 
    long long sum = 0;
    for(int i = 0;i<n;i++){
        int Min = 200000000;
        for(int j = 0;j<n;j++){
            if(arr[i].color == arr[j].color && i != j){
                 Min = min(Min,abs(arr[i].x - arr[j].x));  
            }
        }
        sum = sum + Min;
    }
    cout << sum;
 
}
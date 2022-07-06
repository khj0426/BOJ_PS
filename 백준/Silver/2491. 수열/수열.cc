#include <iostream>
using namespace std;
int arr[100010];
int Min[100010];
int Max[100010];
int main(void){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        Min[i] = 1;
        Max[i] = 1;
        cin >> arr[i];
    }
 
    int max_length = 1;
 
    for(int i = 1;i<n;i++){
 
        if(arr[i] >= arr[i-1]){
            Max[i] = Max[i-1] + 1;
        }
        if(Max[i] > max_length){
            max_length = Max[i];
        }
 
 
    }
 
    for(int i = 1;i<n;i++){
 
        if(arr[i] <= arr[i-1]){
            Min[i] = Min[i-1] + 1;
        }
 
        if(Min[i] > max_length){
            max_length = Min[i];
        }
 
    }
    cout << max_length;
 
 
}
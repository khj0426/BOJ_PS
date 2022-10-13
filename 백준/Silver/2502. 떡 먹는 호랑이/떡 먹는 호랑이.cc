#include <iostream>
using namespace std;
struct data{
    int a;
    int b;
};
 
typedef struct data d;
 
int main(void){
    int n,k;
    cin >> n >> k;
    d arr[32];
    for(int i = 1;i<=n;i++){
        if(i == 1){
            arr[i].a = 1;
            arr[i].b = 0;
        }
        else if(i == 2){
            arr[i].a = 0;
            arr[i].b = 1;
        }
        else{
            arr[i].a = arr[i-1].a + arr[i-2].a;
            arr[i].b = arr[i-1].b + arr[i-2].b;
        }
    }
    int final_a = 0;
    int final_b = 0;
    int sum = 0;
 
    for(int i = 1;i*arr[n].a<=k;i++){
        for(int j = 1;j*arr[n].b<=k;j++){
            sum = (arr[n].a * i) + (arr[n].b * j);
 
            if(sum == k){
                cout << i << '\n';
                cout << j;
                return 0;
            }
        }
    }
 
 
}
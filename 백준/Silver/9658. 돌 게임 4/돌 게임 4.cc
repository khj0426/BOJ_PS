#include <iostream>
using namespace std;
 int arr[1001];
int main(void){
   
    for(int i = 1;i<=1000;i++){
        if(i == 1){
            arr[i] = 1;
            arr[i+7] = 1;
        }
        else if(i == 2){
            arr[i] = 0;
        }
        else if(i == 3){
            arr[i] = 1;
            arr[i+7] = 1;
        }
        else{
            if(arr[i] == 1){
                arr[i+7] = 1;
            }
           
        }
        
    }
    int n;
    cin >> n;
    if(arr[n] == 1){
        cout << "CY";
    }
    else{
cout << "SK";}
}
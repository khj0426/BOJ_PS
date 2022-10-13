#include <iostream>
 
using namespace std;
 //백준 2775 부녀회장이 될테야 

int main(void){
 
    int t;
    cin >> t;
 
 
    for(int i = 0;i<t;i++){
 
        int sum = 0;
         int arr[16][16];
         int n,k;
         cin >> n >> k;
 
        for(int j = 0;j<n+1;j++){
            for(int q = 0;q<k;q++){
                if(q == 0){
                    arr[j][q] = 1;
                }
                else if(j == 0){
                    arr[j][q] = q+1;
                }
                else{
                    arr[j][q] = arr[j][q-1] + arr[j-1][q];
                }
 
            }

        }
    }
 
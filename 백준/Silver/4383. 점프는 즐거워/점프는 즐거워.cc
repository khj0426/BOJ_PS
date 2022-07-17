#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int main(void){
    int n;
    while(scanf("%d",&n) != EOF){
        int arr[3001];
        bool check[3001];

        for(int i = 0;i<n;i++){
            cin >> arr[i];
            check[i] = false;
        }
        
        bool checking = false;
        for(int i = 0;i<n-1;i++){
            int diff = abs(arr[i] - arr[i+1]);
           
            if(diff >= n || diff <= 0 || check[diff] == true){
                checking = true;
                break;
            }
             check[diff] = true;
        }
        
        if(checking == false){
            cout << "Jolly" << '\n';
        }
        else if(checking == true){
            cout << "Not jolly" << '\n';
        }
   
}
}
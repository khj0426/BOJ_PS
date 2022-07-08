#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main(void){
    int n;
    cin >> n;
    string arr[21];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
 
    bool INCREASING = false;
 
    for(int i = 0;i<n-1;i++){
        if(arr[i+1] > arr[i]){
 
            INCREASING = true;
            break;
        }
    }
 
    if(INCREASING == false){
        cout << "DECREASING";
        return 0;
    }
 
 
    INCREASING = false;
     for(int i = 0;i<n-1;i++){
        if(arr[i+1] < arr[i]){
 
            INCREASING = true;
            break;
        }
    }
 
    if(INCREASING == false){
        cout << "INCREASING";
        return 0;
    }
 
    cout << "NEITHER";
    return 0;
 
}
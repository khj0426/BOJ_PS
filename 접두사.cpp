#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//백준 1141 접두사

int main(void){
    int n;
    cin >> n;
    
    string arr[50];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
     sort(arr,arr+n);
     int count = n;
    
      for(int i = 0;i<n;i++){
       string temp = arr[i+1].substr(0,arr[i].size());
       if(temp == arr[i]){
          count--;
       }
    }
    cout << count;
    
}
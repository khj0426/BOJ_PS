#include <iostream>
#include <string>
using namespace std;
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
 
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
return b;}
}
int main(void){
    string arr[20001];
    int n;
    int max_size = 0;
    int l = n;
    int r = n;
 
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];

    }
 
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] == arr[j]){
                continue;
            }
            int length = min(arr[i].size(),arr[j].size());
            if(length == arr[i].size()){
                int temp = 0;
                for(int k = 0;k<arr[i].size();k++){
                    if(arr[i][k] != arr[j][k]){
                        break;
                    }
                    temp++;
                }
             
                if(temp > max_size){
                    max_size = temp;
                    l = i;
                    r = j;
                }
            
            }
           else if(length == arr[j].size()){
               int temp = 0;
               for(int k = 0;k<arr[j].size();k++){
                   if(arr[i][k] != arr[j][k]){
                       break;
                   }
                   temp++;
         
               }
             
               if(temp > max_size){
                   max_size = temp;
                   l = i;
                   r = j;
               }
          
           }                  
             
        }
    }
     int small = min(l,r);
     int big = max(l,r);

    cout << arr[small] << '\n';
     cout << arr[big];
 
}
 
 
 
 
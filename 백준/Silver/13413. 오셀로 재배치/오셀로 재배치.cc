#include <iostream>
#include <string>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        int cnt = 0;
        cin >> n;
       
        char arr[100001];
        char a[100001];
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        for(int i = 0;i<n;i++){
            if(a[i] != arr[i] && a[i] == 'B'){
                for(int j = i+1;j<n;j++){
                    if(a[j] == 'W' && arr[j] == 'B'){
                        char temp = a[j];
                        a[j] = a[i];
                        a[i] = temp;
                        cnt++;
                        break;
                    }
                }
            }
            else if(a[i] != arr[i] && a[i] == 'W'){
                for(int j = i+1;j<n;j++){
                    if(a[j] == 'B' && arr[j] == 'W'){
                        char temp = a[j];
                        a[j] = a[i];
                        a[i] = temp;
                        cnt++;
                        break;
                    }
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            if(a[i] != arr[i]){
                cnt++;
            }
        }
        cout << cnt << '\n';
    
    }
}
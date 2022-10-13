#include <iostream>
using namespace std;
int main(void){
    char arr[20000];
    bool visited[20000] = {false, };
    int n,k;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == 'P'){
            for(int j = i-k;j<=i+k;j++){
                if(visited[j] == false && arr[j] == 'H'){
                    cnt++;
                    visited[j] = true;
                    break;
                }
            }
        }
    }
    cout << cnt;
}
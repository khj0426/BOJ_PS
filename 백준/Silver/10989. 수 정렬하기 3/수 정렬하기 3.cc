#include <iostream>
using namespace std;
int main(void){
     ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[10001] = {0, };
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        arr[x]++;
    }
    
    for(int i = 0;i<10001;i++){
        for(int j = 0;j<arr[i];j++){
            cout << i << '\n';
        }
    }
}
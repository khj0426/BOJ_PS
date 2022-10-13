#include <iostream>
using namespace std;
//백준 7568 덩치
int main(void){
    int bulk[50][2]; //fat and tall
    int index[50];
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> bulk[i][0];
        cin >> bulk[i][1];
    }
 
    for(int i = 1;i<=n;i++){
        index[i] = n;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(!(bulk[j][0] > bulk[i][0] && bulk[j][1] > bulk[i][1])){
                index[i]--;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout << index[i]+1 << ' ';
    }
}
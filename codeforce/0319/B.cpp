#include <iostream>
#include <algorithm>
#include <vector>
//짝수 Mihai

//홀수 Bianca

using namespace std;
bool cmp(int a,int b){
    return a>b;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int odd = 0;
        int even = 0;
      
        for(int i = 0;i<n;i++){
            int num;
            cin >> num;
            if(num % 2 == 0){
                even += num;
            }
            else{
                odd += num;
            }
        }

        

        if(even > odd){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
}




#include <iostream>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int cnt = 0;
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(b>a){
            cnt++;
        }
         if(c>a){
            cnt++;
        }
        if(d>a){
            cnt++;
        }
         cout << cnt << '\n';
    }
 
}
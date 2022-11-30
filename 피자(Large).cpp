#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
vector<ll> v;
 
int main(void){
    int n;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    else if(n == 2){
        cout << 1;
        return 0;
    }
 
    ll prev_value = 1;
    for(int i = 2;i<n;i++){
        ll next_value = (1 * (i)) + prev_value;
        prev_value = next_value;
    }
    cout << prev_value;
 
}
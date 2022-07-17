#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
struct food{
    ll A;
    ll B;
};

ll min(ll a,ll b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
typedef struct food F;

ll ans = 9987654321;
int n;
F arr[11];
vector<int> v;

void dfs(int start){
    if(start >= n){
        if(start == n){
            ll a = 1;
            ll b = 0;
            for(int i = 0;i<v.size();i++){
                a = a * arr[v[i]].A;
                b = b + arr[v[i]].B;
            }
            if(v.size() != 0){
                ans = min(ans,llabs(a-b));
            }
            
        }
        return;
    }
    
    dfs(start+1);
    v.push_back(start);
    dfs(start+1);
    v.pop_back();
    
}
int main(void){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i].A >> arr[i].B;
    }
    dfs(0);
    if(n == 1){
        cout << llabs(arr[0].B - arr[0].A);
        return 0;
    }
    
    cout << ans;
}

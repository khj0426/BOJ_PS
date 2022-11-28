#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef pair<int,int> p;
 
vector<p> v;
int n,m;
 
 
bool cmp(p a,p b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    else if(a.first == b.first){
        return a.second < b.second;
    }
}
 
void init(){
    cin >> n;
    cin >> m;
    for(int i = 0;i<m;i++){
        int A,B; 
        cin >> A >> B;
        v.push_back({A,B});
    }
    sort(v.begin(),v.end());
}
 
int solve(){
    int ans = 0;
    int prev_firstRoom = v[0].first;
    int prev_lastRoom = v[0].second;
 
   for(int i = 1;i<m;i++){
       if(v[i].first <= prev_lastRoom){
           prev_lastRoom = max(v[i].second,prev_lastRoom);
       }    
       else{
           ans += (prev_lastRoom - prev_firstRoom);
           prev_firstRoom = v[i].first;
           prev_lastRoom = v[i].second;
       }
   }
       ans += (prev_lastRoom - prev_firstRoom);
       return ans;
}
 
int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    init();
    if(m == 0){
        cout << n;
    }
    else{
        cout << n-solve();
    }
    
}
 

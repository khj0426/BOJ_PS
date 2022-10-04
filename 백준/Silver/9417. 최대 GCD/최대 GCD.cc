#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;
 
int t;
vector<int> v;
string line;
string word;
int ans = -987654321;

void solve(){
    cin >> t;
    cin.ignore();
    
    while(t--){
        v.clear();
        ans = -987654321;
        
        getline(cin,line);
        stringstream sstream(line);
        
        while(getline(sstream,word,' ')){
            v.push_back(stoi(word));
        }
        
        for(int i = 0;i<v.size();i++){
            for(int j = i+1;j<v.size();j++){
                ans = max(ans,gcd(v[i],v[j]));
            }
        }
        cout << ans << '\n';
    }
 
}
int main(void){
    solve();
}
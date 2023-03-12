#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;
 
 //중복이 없다면 unordered_map사용을 생각하자!
 
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
 
    unordered_map<string,string> memo;
    unordered_map<string,string>::iterator iter;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        memo[str] = str;
    }
 
    for(int i = 0;i<m;i++){
        int ans = memo.size();
 
        string keyword;
        cin >> keyword;
        istringstream ss(keyword);
        string buffer;
        vector<string> v;
 
        while(getline(ss,buffer,',')){
            v.push_back(buffer);
        }
 
        for(int j = 0;j<v.size();j++){
            iter = memo.find(v[j]);
            if(iter != memo.end()){
                memo.erase(iter->first);
                ans--;
            }
        }
        cout << ans << '\n';
    }
}
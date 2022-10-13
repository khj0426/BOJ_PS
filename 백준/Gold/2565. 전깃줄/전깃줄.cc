#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
 
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}
 
int arr[501];
int dp[501];
vector<pair<int,int>> v;
 
int main(void){
 
    int max_dp = 0;
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int A,B;
        cin >> A >> B;
        v.push_back({A,B});
    }
 
    sort(v.begin(),v.end(),cmp);
    
    for(int i = 0;i<v.size();i++){
        dp[v[i].first] = 1;
        for(int j = 0;j<i;j++){
            if(v[i].second > v[j].second && dp[v[j].first] + 1 > dp[v[i].first]){
                dp[v[i].first] = dp[v[j].first] + 1;
            }
        }
        max_dp = max(max_dp,dp[v[i].first]);
    }
  
    cout << n - max_dp;
 
}
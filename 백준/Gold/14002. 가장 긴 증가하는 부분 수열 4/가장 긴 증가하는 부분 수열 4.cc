#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int arr[1001];
    int n;
    cin >> n;
    int dp[1001];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        dp[i] = 1;
    }
 
    int max_ = 1;
    int index = 1;
	int max_dp = -1;
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[i] > arr[j] && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                if(i > index){
                    index = i;
                }
                if(dp[i] > max_){
                    max_ = dp[i];
                }
 
            }
        }
    }
    for(int i = 0;i<n;i++){
    	if(dp[i] > max_dp){
    		max_dp = dp[i];
    	}
    }
 
    vector<int> v;
 
    for(int i = index;i>=0;i--){
        if(v.size() == max_dp){
            break;
        }
        if(max_ == dp[i]){
            v.push_back(arr[i]);
            max_--;
        }
    }
 
    cout << v.size() << '\n';
    reverse(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        cout << v[i] << ' ';
    }
 
 
}
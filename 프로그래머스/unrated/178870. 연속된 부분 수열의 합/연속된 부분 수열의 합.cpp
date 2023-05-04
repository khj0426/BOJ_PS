#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

bool cmp(pair<int,int> a,pair<int,int> b){
    if((b.second-b.first) != (a.second - a.first)){
        return (a.second-a.first) < (b.second-b.first);
    }
    else{
        return a.first < b.first;
    }
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int,int>> v;
    for(int i = 0;i<sequence.size();i++){
        if(i == 0){
            dp[i] = sequence[i];
        }
        else{
            dp[i] = dp[i-1] + sequence[i];
        }
        if(sequence[i] == k){
            answer.push_back(i);
            answer.push_back(i);
            return answer;
        }
    }
    int l = 0;
    int r = 0;
    int sum = sequence[0];
    while(l<=r && r<sequence.size()){
       
        if(sum + sequence[r] <= k){
            r++;
            sum += sequence[r];
        }
        else if(sum + sequence[r] > k){
            sum -= sequence[l];
            l++;
        }
        
        if(sum == k){
            v.push_back({l,r});
        }
    }
    
    sort(v.begin(),v.end(),cmp);
    answer.push_back(v[0].first);
    answer.push_back(v[0].second);
    
    return answer;
}
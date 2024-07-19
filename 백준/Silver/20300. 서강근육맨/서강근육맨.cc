#include <algorithm>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

bool cmp(pair<int,long long> a,pair<int,long long> b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}
 long long arr[100000];

int main(void){
    int n;
    vector<pair<int,long long>> v;
   
    cin >> n;
    

    for(int i = 0;i<n;i++){
        long long m;
        cin >> m;
        v.push_back({i,m});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    if(v.size() % 2 == 0){
        //짝수라면
        for(int i = 0;i<v.size()/2;i++){
            long long sum = v[i].second + v[v.size()-1-i].second;
            arr[i] = sum;
        }
        long long maxM = 0;
        for(int i = 0;i<v.size();i++){
            maxM = max(maxM,arr[i]);
        }
        cout << maxM;
    }
    else{
        //홀수라면
        //최대값?
        long long maxM = 0;
        maxM = max(maxM,v[v.size()-1].second);
        for(int i = 0;i<v.size()/2;i++){
            long long sum = v[i].second + v[v.size()-2-i].second;
            arr[i] = sum;
        }
        
        for(int i = 0;i<v.size();i++){
            maxM = max(maxM,arr[i]);
        }
        cout << maxM;
    
    }
    
}

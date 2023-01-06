#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//13254523
//4개

//1 1
//2 2
//3 2
//4 1
//5 2

//5 3 2 1 4
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else{
        return a.first < b.first;
    }
    
}
int solution(int k, vector<int> tangerine) {
    map<int,int> countOfNumber;
    map<int,int>::iterator iter;
    
    int answer = 0;
    for(int i = 0;i<tangerine.size();i++){
        iter = countOfNumber.find(tangerine[i]);
        if(iter == countOfNumber.end()){
            countOfNumber.insert({tangerine[i],1});
        }
        else{
            countOfNumber[tangerine[i]]++;
        }
    
    }
    vector<pair<int,int>> v;
    for(iter = countOfNumber.begin();iter != countOfNumber.end();iter++){
       v.push_back({iter->first,iter->second});
    }
    
    sort(v.begin(),v.end(),cmp);
    for(int i = 0;i<v.size();i++){
        if(k <= 0){
            break;
        }
        k -= v[i].second;
        answer += 1;
        
     
    }
    
    
    
    
    
    return answer;
}
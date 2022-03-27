#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string,int> a,pair<string,int> b){
    return a.second < b.second;
}

int main(void){
    vector<pair<string,int>> v;
    vector<pair<string,int>>::iterator viter;
    
    map<string,int> m;
    map<string,int>::iterator iter;
    int k,l;
    cin >> k >> l;
    for(int i = 0;i<l;i++){
        string num;
        cin >> num;
        iter = m.find(num);
        if(iter != m.end()){ //이미 학번이 있는경우
            m[num] = i;
        }
        else if(iter == m.end()){
            m.insert(pair<string,int>(num,i));
        }
    }
    for(iter = m.begin();iter != m.end();iter++){
        v.push_back(pair<string,int>(iter->first,iter->second));
    }
    
    sort(v.begin(),v.end(),cmp);
    int count = 0;
    
    for(viter = v.begin();viter != v.end();viter++){
        if(count == k){
            break;
        }
        cout << viter->first << '\n';
        count++;
    }
    
    
}
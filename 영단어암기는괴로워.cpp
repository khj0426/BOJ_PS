#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
//백준 20920 영단어 암기는 괴로워

using namespace std;
bool cmp(pair<string,int> a,pair<string,int> b){
    if(a.second != b.second){
        if(a.second > b.second){
            return true;
        }
        else if(a.second < b.second){
            return false;
        }
    }
    else if(a.second == b.second && a.first.size() != b.first.size()){
        if(a.first.size() > b.first.size()){
            return true;
        }
        else if(a.first.size() < b.first.size()){
            return false;
        }
    }
    else{
        return a.first<b.first;
    }
}
 
int main(void){
    map<string,int> m;
    map<string,int>::iterator iter;
 
    int n,l;
    cin >> n >> l;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        if(str.size()>=l){
        iter = m.find(str);
        if(iter == m.end()){
            m.insert(pair<string,int>(str,1));
        }
        else if(iter != m.end()){
            m[str]++;
        }
    }
        }
 
    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    vector<pair<string,int>>::iterator vter;
    for(vter = v.begin();vter != v.end();vter++){
        cout << vter->first << '\n';
    }
 
}
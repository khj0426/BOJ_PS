#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
//백준 13414 수강신청
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
        if(iter != m.end()){ //이미 학번이 있는경우 i가 큰 순서로 갱신
            m[num] = i;
        }
        else if(iter == m.end()){ //학번이 없는 경우 map에 넣기
            m.insert(pair<string,int>(num,i));
        }
    }
    for(iter = m.begin();iter != m.end();iter++){ //map의 요소를 vector에 넣어두기
        v.push_back(pair<string,int>(iter->first,iter->second));
    }
    
    sort(v.begin(),v.end(),cmp);//vector의 second기준으로 오름차순 정렬(i가 작은순서대로)
    int count = 0;
    
    for(viter = v.begin();viter != v.end();viter++){
        if(count == k){
            break;
        }
        cout << viter->first << '\n';
        count++;
    }
    
    
}
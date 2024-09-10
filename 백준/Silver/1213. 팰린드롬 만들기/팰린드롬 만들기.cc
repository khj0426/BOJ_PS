//한수으 영어이름의 알파벳 순서를 바꿔 펠린드롬


//가장 많이 나온거 부터 앞뒤로 추가 ㄱㄱ
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void){
    string str;
    cin >> str;
    map<char,int> m;
    map<char,int>::iterator iter;
    
    vector<char> v;
    for(int i = 0;i<str.size();i++){
        v.push_back(str[i]);
        iter = m.find(str[i]);
        if(iter == m.end()){
            m[str[i]] = 1;
        }
        else{
            int c = iter->second;
            m[str[i]] = c+1;
        }
    }
    sort(v.begin(),v.end());
    
    string start_str = "";
    string end_str = "";
    string mid_str = "";
    
    for(int i = 0;i<v.size();i++){
        int c = m[v[i]];
        if(m[v[i]] == 0){
            continue;
        }
        if(c == 1){
            reverse(mid_str.begin(),mid_str.end());
            mid_str += v[i];
            m[v[i]]--;
        }
        else{
            if(c % 2 == 0){
                for(int j = 0;j<(c/2);j++){
                    start_str += v[i];
                }
                for(int j = 0;j<(c/2);j++){
                    end_str += v[i];
                }
                m[v[i]] = 0;
            }
            
            //7->3 3 1
            else{
                for(int j = 0;j<(c/2);j++){
                    start_str += v[i];
                }
                for(int j = 0;j<(c/2);j++){
                    end_str += v[i];
                }
                m[v[i]] = 1;
            }
        }
    }

    reverse(end_str.begin(),end_str.end());
    string new_str = start_str;
    if(mid_str.size() > 0){
        new_str += mid_str;
    }
    if(end_str.size() > 0){
        new_str += end_str;
    }
    
    string STR = new_str;
    reverse(new_str.begin(),new_str.end());
    
    if(new_str != STR){
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    else{
        cout << new_str;
        return 0;
    }
}
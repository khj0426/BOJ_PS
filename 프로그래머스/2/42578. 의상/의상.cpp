#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;
    map<string,int>::iterator iter;
    
    //
    for(int i = 0;i<clothes.size();i++){
        iter = m.find(clothes[i][1]);
        if(iter == m.end()){
            m[clothes[i][1]] = 2;
        }
        else{
            int val = iter->second;
            m[clothes[i][1]] = (val + 1);
        }
    }
    
    int val = 1;
    for(iter = m.begin();iter != m.end();iter++){
        val *= iter->second;
    }
    return val-1;
}
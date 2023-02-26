#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

string toStr(int n,int m){
    //정수 n을 받아서 m진수의 문자열 형태로 반환
    map<int,char> toAlpha;
    map<int,char>::iterator iter;
    //10부터 15 숫자 처리
    
    toAlpha[10] = 'A';
    toAlpha[11] = 'B';
    toAlpha[12] = 'C';
    toAlpha[13] = 'D';
    toAlpha[14] = 'E';
    toAlpha[15] = 'F';
    string ans = "";
    
    vector<int> v;
    while(n > 0){
        int divide = n / m;
        int mode = n % m;
        v.push_back(mode);
        n = divide;
    }
    
    reverse(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        iter = toAlpha.find(v[i]);
        if(iter != toAlpha.end()){
            char ch = iter->second;
            ans += ch;
        }
        else{
            ans.append(to_string(v[i]));
        }
    }
    
    return ans;
    
}

//0 1 2 3 4 5

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    
    vector<char> ans;
    
    ans.push_back('0');
    int order = 1;
    int size_ = t;
    while(t>0){
        //0 1 2 3 4 5
        //0 1 1 0 1 1
        for(int i = 1;i<=m;i++){
            string str = toStr(num,n);
            for(int j = 0;j<str.size();j++){
                ans.push_back(str[j]);
            }
            if(i == p){
                t--;
            }
            num++;
        }
    }
    
    for(int i = p-1;i<ans.size();i+=m){
        if(answer.size() == size_){
            break;
        }
        answer.push_back(ans[i]);
    }
    
    
    return answer;
}
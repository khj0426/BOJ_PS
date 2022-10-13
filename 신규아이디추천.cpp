#include <string>
#include <vector>
#include <iostream>
#include <cctype>
 //프로그래머스 신규 아이디 추천
 
using namespace std;
 
string solution(string new_id) {
    string answer = "";
 
    for(int i = 0;i<new_id.size();i++){
        if(new_id[i] >='A' && new_id[i] <= 'Z'){
            new_id[i] = new_id[i]+32; //소문자 = 대문자 + 32
        }
    }
    string str = "";
 
    for(int i = 0;i<new_id.size();i++){
        if(new_id[i] >= 'a' && new_id[i] <= 'z' || isdigit(new_id[i]) != 0 || new_id[i] == '_' || new_id[i] == '-' || new_id[i] == '.'){
            str = str + new_id[i];
        }
    }
    string st = "";
    int count = 0;
    for(int i = 0;i<str.size();i++){
        if(str[i] == '.'){
           if(str[i] == '.' && str[i+1] != '.' || str[i] == '.' && i == str.size()-1){
               st = st + '.';
 
           }
        }
        else{
            st = st + str[i];
        }
    }
 
if(st[0] == '.'){
    st[0] = ' ';
}
    if(st[st.size()-1] == '.'){
        st[st.size()-1] = ' ';
    }
    
    string temp = "";
    for(int i = 0;i<st.size();i++){
        if(st[i] != ' '){
            temp = temp + st[i];
        }
    }
    
    if(temp == ""){
        temp = "a";
    }
    string f_temp = "";
    if(temp.size()>=16){
        for(int i = 0;i<15;i++){
            f_temp = f_temp + temp[i];
        }
    }
    if(f_temp[f_temp.size()-1] == '.'){
        string Tmp = "";
        for(int i = 0;i<14;i++){
            Tmp = Tmp + f_temp[i];
        }
        f_temp = Tmp;
    }
    if(temp.size() < 16){
        f_temp = temp;
    }
    if(f_temp.size()<=2){
        char ch = ' ';
        for(int i = 0;i<f_temp.size();i++){
            ch = f_temp[i];
        }
        while(1){
            if(f_temp.size() == 3){
                break;
            }
            f_temp = f_temp + ch;
        }
    }
 
    answer = f_temp;
    return answer;
}
 
int main(void){
    string st;
    cin >> st;
    cout << solution(st);
}
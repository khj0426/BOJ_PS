#include <string>
#include <stack>
#include <iostream>

using namespace std;

int check_valid_str(string s){
    stack<char> st;
    for(int i = 0;i<s.size();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            if(s[i] == ')' && st.top() == '('){
                st.pop();
            }
            else if(s[i] == ']' && st.top() == '['){
                st.pop();
            }
            else if(s[i] == '}' && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    if(st.empty()){
        return 1;//valid
    }
    else if(!st.empty()){
        return -1;//not valid
    }
    
}
    
int solution(string s) {
    int answer = 0;
    string str = s;
    int value = check_valid_str(str);
    if(value == 1){
        answer++;
    }
    
      for(int i = 1;i<s.size();i++){
        char temp = str[0];
        str += temp;
        str.erase(str.begin());
        int value = check_valid_str(str);
        if(value == 1){
            answer++;
        }
    }
    return answer;
}
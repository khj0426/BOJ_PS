#include <iostream>
#include<string>
#include<stack>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    
    for(int i = 0;i<s.size();i++){
        if(st.size() == 0){
            st.push(s[i]);
        }
        else{
            if(st.top() != s[i]){
                st.push(s[i]);
            }
            else{
                while(st.size() > 0){
                    if(st.top() != s[i]){
                        break;
                    }
                    if(st.size() == 0){
                        break;
                    }
                    if(st.top() == s[i]){
                        st.pop();
                    }
                }
            }
        }
    }
    
    if(st.size() == 0){
        return 1;
    }
    return 0;
}
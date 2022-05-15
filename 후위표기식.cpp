#include <iostream>
#include <stack>
#include <string>

//백준 1918 후위표기식

using namespace std;
int width(char c){
    if(c == '*' || c == '/'){ //*와 나누기-> 가장 큰 가중치
        return 3;
    }
    else if(c == '+' || c == '-'){ //+와 뺴기(-) -> 두번쨰로 큰 가중치
        return 2;
    }
    else if(c == '('){ //연산자 중 가장 낮은 가중치
        return 0;
    }
    else{ //연산자가 아닌 경우
        return -1;
    }
}
 
int main(void){
    stack<pair<char,int>> st; 
    string str;
    cin >> str;
    
    for(int i = 0;i<str.size();i++){
        int w = width(str[i]);
        if(w == -1 && str[i] != ')'){
            cout << str[i];
        }
        else if(str[i] == ')' && w == -1){
            while(st.top().first != '('){
                if(st.empty()){
                    break;
                }
                if(st.top().first != '('){
                    cout << st.top().first;
                    st.pop();
                }
            }
            if(st.top().first == '('){
            	st.pop();
            }
        }
        else if(w != -1){
            if(w == 0){
                st.push({str[i],w});
            }
            else if(w == 2){
                if(st.empty()){
                    st.push({str[i],w});
                }
                else{
                    while(1){
                        if(st.empty()){
                            break;
                        }
                        else if(st.top().second < w){
                            break;
                        }
                        cout << st.top().first;
                        st.pop();
                    }
                    st.push({str[i],w});
                }
            }
            else if(w == 3){
                if(st.empty()){
                    st.push({str[i],w});
                }
                else{
                    while(1){
                        if(st.empty()){
                            break;
                        }
                        else if(st.top().second < w){
                            break;
                        }
                        cout << st.top().first;
                        st.pop();
                    }
                    st.push({str[i],w});
                }
            }
        }
    }
    while(!st.empty()){
        cout << st.top().first;
        st.pop();
    }
 
}
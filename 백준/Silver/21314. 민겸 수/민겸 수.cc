//k를 붙여가는게 가장 큰 경우
//k를 잘라나가는게 가장 작은 경우
//ll->overflow발생
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;
string str;
 
string find_max(){
    stack<char> st;
    int M = 0;
    int K = 0;
    int ans = 0;
    string temp = "";
    for(int i = 0;i<str.size();i++){
        if(st.empty()){
            if(str[i] == 'K'){
                temp.append(to_string(5));
            }
            else if(str[i] == 'M'){
                st.push(str[i]);
            }
        }
        else{
            if(st.top() == 'M' && str[i] == 'K'){
                temp.append(to_string(5));
                for(int i = 0;i<st.size();i++){
                    temp.append(to_string(0));
                }
                while(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(str[i]);
            }
        }
    }
 
       if(!st.empty()){
           for(int i = 0;i<st.size();i++){
               temp.append(to_string(1));
           }
       }
 
 
    return temp;
}
 
string find_min(){
    vector<char> M;
    string temp = "";
    for(int i = 0;i<str.size();i++){
        if(str[i] == 'K'){
            if(!M.empty()){
                temp.append(to_string(1));
                for(int i = 0;i<M.size()-1;i++){
                    temp.append(to_string(0));
                }
                temp.append(to_string(5));
                M.clear();
            }
            else if(M.empty()){
                temp.append(to_string(5));
            }
        }
        else if(str[i] == 'M'){
            M.push_back('M');
        }
    }
 
    if(!M.empty()){
        temp.append(to_string(1));
        for(int i = 0;i<M.size()-1;i++){
            temp.append(to_string(0));
        }
 
    }
    return temp;
}
 
 
int main(void){
    cin >> str;
    cout << find_max() << '\n';
    cout << find_min();
}
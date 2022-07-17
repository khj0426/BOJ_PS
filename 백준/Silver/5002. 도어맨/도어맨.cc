#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <cmath>
 
char str[101];
 
using namespace std;
int main(void){
    stack<char> st;
    int n;
    cin >> n;
 
    cin >> str;
    int length = 0;
 
    int W = 0;
    int M = 0;
 
 
    for(int i = 0;i<strlen(str);i++){
 
            if(str[i] == str[i+1] && str[i+1] != str[i+2]){
                char temp = str[i+2];
                str[i+2] = str[i+1];
                str[i+1] = temp;
 
            }
 
    }
 
    for(int i = 0;i<strlen(str);i++){
 
        if(abs(M-W) > n){
            length--;
            break;
        }
        if(st.empty()){
            st.push(str[i]);
            length++;
            if(str[i] == 'W'){
                W++;
            }
            else if(str[i] == 'M'){
                M++;
            }
        }
        else{
 
            if(st.top() == 'M' && str[i] == 'W'){
                st.pop();
                length++;
                if(M != 0){
                    M--;
                }
                if(W != 0){
                     W--;
                }
 
            }
            else if(st.top() == 'W' && str[i] == 'M'){
                st.pop();
                length++;
                if(M != 0){
                    M--;
                }
                if(W != 0){
                     W--;
                }
 
            }
            else{
                st.push(str[i]);
                length++;
                if(str[i] == 'W'){
                    W++;
                }
                else if(str[i] == 'M'){
                    M++;
                }
            }
        }
    }
    cout << length;
 
}
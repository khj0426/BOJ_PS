#include <iostream>
#include <string>
 
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
using namespace std;
 
int main(void){
    string str;
    cin >> str;
 
    int zero = 0; //연속된 '0'구간의 개수
    int first = 0; //연속된 '1'구간의 개수
    bool is_zero = false;
    for(int i = 0;i<str.size();i++){
       if(i == 0){
           if(str[i] == '0'){
               is_zero = true;
           }
           else if(str[i] == '1'){
               is_zero = false;
           }
       }
        else{
            if(str[i] == '0' && is_zero == false){
                first++;
                is_zero = true;
            }
            else if(str[i] == '1' && is_zero == true){
                zero++;
                is_zero = false;
            }
        }
    } 
    if(is_zero == false){
        first++;
    }
    else{
        zero++;
    }
 
   cout << min(zero,first);
 
}
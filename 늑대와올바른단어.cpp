#include <iostream>
#include <vector>
#include <string>
using namespace std;
//백준 13022 늑대와 올바른 단어

int main(void){
    vector<char> v;
    int num[4] = {0, }; //'w,o,l,f의 개수를 담을 배열'
    string str;
    cin >> str;
    bool is_correct = true;
    
    for(int i = 0;i<str.size();i++){
        if(str[i] == 'w'){ //w인경우 
            num[0]++;
        }
        else if(str[i] == 'o'){ //o인경우
            num[1]++;
            
        }
        else if(str[i] == 'l'){ //l인경우
            num[2]++;
           
        }
        else if(str[i] == 'f'){ //f인경우
            num[3]++;
            if(str[i+1] == 'w'){ //만약 wolf가 한 단위라면(f다음 w가왔을때)
                  for(int i = 0;i<4;i++){
                   for(int j = 0;j<4;j++){
                       if(num[i] != num[j]){
                           is_correct = false; //num값이 서로 다르면 올바르지 않은 문자열
               }
           }
       }
            }
        }
 
        if(i>=1){ //i가 1이상일떄
            if(str[i] == 'w'){
                if(str[i-1] == 'w' || str[i-1] == 'f'){ //이 경우만 올바른 단어
                    v.push_back(str[i]);
                }
                else{
                    is_correct = false;    
                }
            }
            else if(str[i] == 'o'){ 
                if(str[i-1] == 'o' || str[i-1] == 'w'){//이 경우만 올바른 단어
                    v.push_back(str[i]);
                }
                else{
                    is_correct = false;
 
                }
            }
            else if(str[i] == 'l'){
                if(str[i-1] == 'l' || str[i-1] == 'o'){//이 경우만 올바른 단어
                    v.push_back(str[i]);
                }
                else{
                    is_correct = false;
                }
            }
            else if(str[i] == 'f'){
                if(str[i-1] == 'l' || str[i-1] == 'f'){//이 경우만 올바른 단어
                    v.push_back(str[i]);
                }
                
                else{
                    is_correct = false;
                   
                }
            }
        }
 
    }
 
    for(int i = 0;i<4;i++){ //num배열의 값이 다르면 올바르지 않은 단어
       for(int j = 0;j<4;j++){
           if(num[i] != num[j]){
               is_correct = false;
           }
       }
    }
 
    if(is_correct == false){
        cout << '0';
    }
    else{
        cout << '1';
    }
 
 
}
 
#include <string>
#include <vector>
#include <iostream>

//프로그래머스 숫자 문자열과 영단어

using namespace std;

int solution(string str) {
    int answer = 0;
    string temp = "";
    string final_string = "";
    
   for(int i = 0;i<str.size();i++){
        if(isdigit(str[i]) == 0){
            temp = temp + str[i];
            if(temp == "one"){
                final_string = final_string + "1";
                temp = "";
            }
            else if(temp == "zero"){
                final_string = final_string + "0";
                temp = "";
            }
            else if(temp == "two"){
                final_string = final_string+ "2";
                temp = "";
            }
            else if(temp == "three"){
                final_string = final_string+ "3";
                temp = "";
            }
            else if(temp == "four"){
                final_string = final_string+ "4";
                temp = "";
            }
            else if(temp == "five"){
                final_string = final_string+ "5";
                temp = "";
            }
            else if(temp == "six"){
                final_string = final_string+ "6";
                temp = "";
            }
            else if(temp == "seven"){
                final_string = final_string+ "7";
                temp = "";
            }
            else if(temp == "eight"){
                final_string = final_string+ "8";
                temp = "";
            }
            else if(temp == "nine"){
                final_string = final_string+ "9";
                temp = "";
            }
        }
        else{
            final_string = final_string + str[i];
        }
    
    }
    answer = stoi(final_string);
    return answer;
}
int main(void){
    
    string str;
    cin >> str;
    
    cout << solution(str);
    return 0;
}
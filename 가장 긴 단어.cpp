#include <iostream>
#include <string>
using namespace std;
 //백준 5637 가장 긴 단어

int main(void){
 
    string arr[10002];
    int index = 0;
    string str = "";
    string max_string = "";
    while(1){   
        if(str == "E-N-D"){
            break;
        }
        char ch = getchar();
 
        if((ch >= 'a' && ch<= 'z') || (ch >='A' && ch<='Z') || (ch == '-')){
            str = str + ch;
        }
        else{
                arr[index] = str;
                index++;   
                str = "";
        }
    }
 
   max_string = "";
   for(int i = 0;i<index;i++){
       if(arr[i].size() > max_string.size()){
           max_string = arr[i];
       }
   }
   for(int i = 0;i<max_string.size();i++){ //마지막에 소문자로 출력하기
       if(max_string[i] >= 'A' && max_string[i] <= 'Z'){
          max_string[i] =  max_string[i]+32;
       }
   }
 
    cout << max_string;
}
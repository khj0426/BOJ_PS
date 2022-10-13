#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str;
    cin >> str;
    string answer;
    answer = "";
    int count = 0;
    int temp = 0;
 
    for(int i = 0;i<str.size();i++){
        if(str[i] == '.'){
            if(count % 2 != 0){
                temp = -1;
                cout << temp;
                return 0;
            }
            else if(count % 2 == 0){
                while(1){
                    if(count == 0){
                        break;
                    }
                    if(count >= 4 ){
                        answer = answer + "AAAA";
                        count = count - 4;
                    }
                    else if(count >= 2 && count < 4){
                        answer = answer + "BB";
                        count = count - 2;
                    }
 
                }
            }
            count = 0;
            answer = answer + '.';
        }
        else if(str[i] == 'X'){
            count++;
        }
    }
 
    if(count % 2 != 0){
        temp = -1;
        cout << temp;
        return 0;
    }
 
    else{
        while(1){
            if(count == 0){
                break;
            }
            if(count >= 4){
                answer = answer + "AAAA";
                count = count - 4;
            }
            else if(count >= 2 && count < 4){
                answer = answer + "BB";
                count = count - 2;
            }
        }
    }
    cout << answer;
}
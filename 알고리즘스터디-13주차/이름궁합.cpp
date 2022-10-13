#include <iostream>
#include <string>
using namespace std;
int index[27] = {0, };
int arr[10000] = {0, };
//백준 15312 이름 궁합(13주차 문제)
 
int main(void){
    string str = "32123323322122122212111221"; //알파벳별 획수에 대한 string
    
    /*A부터 Z까지 index에 횟수 저장하기 */
    for(int i = 0;i<26;i++){
        index[i] = str[i] - 48;
    }
 
    string A_str;
    string B_str;
    cin >> A_str >> B_str;
    string new_str = "";
    //A다음B가 오는 new_str
 
    //new_str만들어주기
    for(int i = 0;i<A_str.size();i++){
        new_str = new_str + to_string(index[A_str[i]-'A']);
        new_str = new_str + to_string(index[B_str[i]-'A']);
    }
    
    
    //횟수를 정수형태로 arr[i]에 저장히기
        for(int i = 0;i<new_str.size();i++){
            arr[i] = new_str[i]-48;
        }
    
    
    while(1){
        int index = 0;
        string temp = "";
            while(1){
                //index가 new_str-1일때 탈출
                if(index == new_str.size()-1){
                    break;
                }
                //arr[index]값은 한칸뒤의 숫자더한 값의 모듈러 10을 해주고 새로운 temp문자열에 이어붙이기
                arr[index] = (arr[index] + arr[index+1])%10;
                temp.append(to_string(arr[index]));
                index++;
            }
        //new_str은 temp->문자열 갱신
        new_str = temp;
        //탈출조건
        if(temp.size() == 2){
            cout << temp;
            break;
        }
    }
       
 
}
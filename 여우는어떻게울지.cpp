#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

//백준 9536 여우는 어떻게 울지?
 
using namespace std;
int main(void){
    int t;
    cin >> t;
     
    /*cin을 통해 입력을 받은 상태->버퍼에 '\n'문자 존재.
    '\n'을 cin.ignore()를 통해 맨 앞의 한 문자를 지움
    ->버퍼 초기화 */
    
    cin.ignore();
    while(t--){
        vector<pair<string,bool>> v; 
        //등장한 울음소리를 true로 바꾸고 false인 울음소리 출력
 
 
        string str;
        getline(cin,str);
 
        string temp = "";
        for(int i = 0;i<str.size();i++){
            if(str[i] == ' '){
                v.push_back({temp,false});
                //' ' 문자라면 울음소리 벡터에 넣고 temp "" 로 바꿔주기(초기값 false)
                temp = "";
            }
            else{
                //그 외의 경우 temp에 이어붙이기
                temp = temp + str[i];
            }
 
        }
        //마지막 temp 벡터에 넣어주기
        v.push_back({temp,false});   
        temp = "";
        
        while(1){
 
            //<동물>goes<소리>의 형태 -> 소리가 벡터에 있으면 소리 bool값 true로 바꾸기
            getline(cin,str);
            if(str == "what does the fox say?"){ //탈출조건
                break;
            }
            
            else{
                /*소리에 대한 정보*/
                for(int i = 0;i<str.size();i++){
                    if(str[i] == ' '){
                        temp = "";
                    }
                    else{
                        temp = temp + str[i];
                    }
                }
                
               for(int i = 0;i<v.size();i++){ //울음소리가 벡터에 있다면 울음소리 true로 바꾸기
                   if(v[i].first == temp){
                       v[i].second = true;
                   }
               }
            }
            
            //입력받을 때마다 clear로 상태 초기화해줘야함
             cin.clear();
        }
 
        /*벡터에 남아있는 false인 소리->여우의 울음소리*/
        for(int i = 0;i<v.size();i++){
            if(v[i].second == false){
                cout << v[i].first << " ";
            }
        }
 
      cout << "\n";
 
    }
}
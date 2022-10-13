#include <iostream>
#include <string>
#include <set>

//백준 2866 문자열 잘라내기

using namespace std;
int main(void){
 
    //0~R까지의 문자열 저장할 배열
    string arr[1001];
  
 
    int r,c;
    cin >> r >> c;
    for(int i = 0;i<r;i++){
        cin >> arr[i];
    }
     string str[1001];
    //새로 잘라서 만들어진 문자열을 담을 배열
    
    
    /* 0~R까지 한 행씩 잘라서 문자열 만드는 방법 ->시간초과
       먼저 아무것도 자르지 않은 문자열을 일단 만들어 둠 */
    /* ex)dobarz
          adatak
          일떄 da,od,ba,at,ra,zk에 해당하는 문자열을 일단 만듬 */
    
    //새로운 문자열 = arr[0][0] + arr[1][0], arr[0][1] + arr[1][1]....

    for(int i = 0;i<c;i++){
        set<string> s;
        set<string>::iterator iter;
        
        for(int j = 0;j<r;j++){
            str[i]+=arr[j][i];
        }

    }
    
    //만들어든 문자열의 substr을 구해서 문자열 셋에 넣고 존재하면 탈출
    
    for(int i = 0;i<r;i++){
         set<string> s;
         set<string>::iterator iter;
        for(int j = 0;j<c;j++){
            string temp = str[j].substr(i); //(str[j][i] - str[j][str[j].size()-1])까지의 문자열
            
            iter = s.find(temp);
            if(iter == s.end()){ //셋에 존재하지 않으면 넣고
                s.insert(temp);
            }
            else{ //셋에 존재하면
                if(i == 0){ //i가 0이면 0출력
                    cout << i;
                    return 0;
                }
                else{ //그 외의 i-1
                   cout << i - 1 << '\n';
                   return 0; 
                }
                
            }
        }
    }
    //모두 겹치는 게 없다면 r-1가 총 count의 개수
    cout << r-1;
 
}
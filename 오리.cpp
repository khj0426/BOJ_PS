#include <iostream>
#include <string>
using namespace std;

//백준 12933 오리

/*
예제 1)
quqacukqauackck

첫번쨰 탐색으로 quackquack 2번 찾을 수 있음 -> 
두번째 탐색으로 quack 1번 찾을 수 있음 
(찾은 오리는 다시 안 찾음 (index를 bool -> true처리))

첫번째 탐색은 오리가 한 오리가 움 quack quack
두번쨰 탐색은 다른 오리가 움 quack
총 2마리의 오리가 있음

예제 2)
kcauq
첫번째 탐색으로 아무것도 찾을 수 없음(q->u->a->c->k의 순서를 만족해야 함)
오리의 울음소리가 유효하지 않음 -1출력

예제 3)
quackquackquackquackquackquackquackquackquackquack
첫번째 탐색으로 quackquackquackquackquackquackquackquackquackquack 모두 찾을 수 있음
오리는 1마리 

예제 4)
qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk
첫번째 탐색으로 quack,
두번째 탐색으로 quack,...10번쨰 탐색으로 quack
오리는 10마리

예제 5)

첫번째 탐색으로 quackquack찾을 수 있음
두번쨰 탐색으로 찾을 수 없음
->탐색이 끝나고 ackqu가 남음 -> 유효하지 않은 울음소리 
*/


bool check_index[2501]; //울음소리를 만족하면 인덱스 true로 바꿈

int main(void){
    int ans = 0; //오리 숫자
    
    string str;
    cin >> str;
    for(int i = 0;i<str.size();i++){
        string temp = "";
        bool valid = false; 
        int index[5] = {0, }; //quack의 인덱스 저장
        
            /*올바른 오리 울음소리 찾기 */
            for(int j = i;j<str.size();j++){
                if(check_index[j] == false){
                    if(str[j] == 'q' && temp == ""){ //q이고 temp가 빈 문자열인 경우
                        index[0] = j;     //index[0]에 q 인덱스 저장
                        temp = temp + 'q'; //temp -> q로 바꿈
                    }
                    if(str[j] == 'u' && temp == "q"){ //u이고 temp가 q인 경우
                        index[1] = j;    //index[1]에 u인덱스 저장
                        temp = temp + 'u'; //temp -> qu로 바뀜
                    }
                    else if(str[j] == 'a' && temp == "qu"){ //a이고 temp가 qu인경우
                        index[2] = j;         //index[2]에 a인덱스 저장
                        temp = temp + 'a';    //temp ->qua로 바뀜
                    }
                    else if(str[j] == 'c' && temp == "qua"){ //c이고 temp가 qua인 경우
                        index[3] = j;        //index[3]에 c인덱스 저장
                        temp = temp + 'c';    //temp->quac로 바뀜
                    }
                    else if(str[j] == 'k' && temp == "quac"){ //k이고 temp가 quac인 경우
                        index[4] = j;        //index[4]에 k인덱스 저장
                        temp = temp + 'k';    //temp->quack로 바뀜
                    }
                }
            
                /*quack일때 temp를 빈 문자열로 바꾸고 인덱스가 오름차순인지 확인*/
                if(temp == "quack"){
                    temp = "";
                    if(index[0] < index[1] && index[1] < index[2] && index[2] < index[3] &&
                      index[3] < index[4]){
                        /*valid가 false인 경우 true로 바꾸고 ans++
                        -> 오리가 연속해서 우는 경우 ans를 갱신 할 필요 없음 */
                        if(valid == false){
                            valid = true;
                            ans++;
                        }
                        /*quack 인덱스 true 처리*/
                        check_index[index[0]] = 1;
                        check_index[index[1]] = 1;
                        check_index[index[2]] = 1;
                        check_index[index[3]] = 1;
                        check_index[index[4]] = 1;
                        
                    }
                    
                }
            }
        }
    
    /*인덱스가 false인 것이 있으면 올바르지 않은 울음소리 */
    for(int i = 0;i<str.size();i++){
        if(check_index[i] == 0){
            cout << -1;
            return 0;
        }
    }

    
    cout << ans;
}
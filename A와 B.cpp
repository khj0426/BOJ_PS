#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//백준 12904 A와 B

//S->T 시간초과
/* T->S
T를 대상으로 DFS실행 
*/

using namespace std;
string s;
string t;
bool is_valid = false;

void input(){
    cin >> s;
    cin >> t;
}

void dfs(string str){
    if(str.size() <= s.size()){
        if(str == s){
            is_valid = true;
        }
        return;
    }
    string first = str;
    if(first[first.size()-1] == 'A'){ //S에서 문자열의 끝에 A를 더한 경우
        // T에서 문자열의 끝 문자를 지우고 DFS
        first.erase(first.size()-1);
        dfs(first);
    }

    string second = str;
    if(second[second.size()-1] == 'B'){ //S에서 문자열을 뒤집고 B를 더한 경우
        /* ex) BA-> ABB T의 문자열의 끝 문자가 B인경우
        ABB에서 끝 문자 B를 지우고 뒤집기
        AB->BA (원래의 문자열로 돌아감)
        */
        second.erase(second.size()-1);
        reverse(second.begin(),second.end());  
        dfs(second);
    }
    

}

int main(void){
    input();
    dfs(t);
    if(is_valid == true){
        cout << 1;
    }
    else{
        cout << 0;
    }
}
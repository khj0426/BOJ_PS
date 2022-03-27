#include <iostream>
#include <queue> //이 헤더파일이 필요합니다

using namespace std;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int> q;  //우선순위 큐의 선언 ->default로 큰 값이 우선순위가 크다.
    
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int element;
        cin >> element;
        if(element != 0){
            q.push(element); //push연산
        }
        else if(element == 0){
            if(q.empty()){ //q.empty() -> 큐가 비어있는지 여부
                cout << '0' << '\n';
            }
            else{
            cout << q.top() << '\n'; //top()->우선순위가 가장 큰 값 리턴
            q.pop(); //pop연산
            }
        }
    }
    
}
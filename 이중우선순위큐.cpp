#include <iostream>
#include <algorithm>
#include <map>
 
using namespace std;
 
 //백준 7662 이중 우선순위 큐(맵 사용)
 
bool compare(int a,int b){
    return a>b;
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
 
    for(int i = 0;i<t;i++){

        multimap<int,int,greater<int>> m; //멀티맵 키 값 기준 내림차순 정렬(greater)
        multimap<int,int,greater<int>>::iterator iter;
        multimap<int,int,greater<int>>::reverse_iterator riter; //반복자,역방향 반복자
        int n;
        cin >> n;
 
        for(int j = 0;j<n;j++){
            int input_x;
            string input;
            cin >> input;
            cin >> input_x;
            if(input == "I"){ //I인경우 데이터의 삽입
                iter = m.find(input_x); 
                if(iter != m.end()){
                    int x = iter->second;
                    m.insert(pair<int,int>(input_x,x+1));
                }
                else{    
                   m.insert(pair<int,int>(input_x,1));
                }
            }
            else if(!m.empty()){ //맵이 비어있지 않는다면
                if(input == "D"){ //D1인 경우 최대값 삭제 (맵에서 가장 앞에 있는 값)
                    if(input_x == 1){ 
                        iter = m.begin(); //맵의 첫번쨰 원소 접근
                        m.erase(m.find(iter->first)); //맵의 첫번째 원소(최대값) 제거
                    }
                    else if(input_x == -1){ //D-1인경우 최소값 삭제(맵에서 가장 뒤에 있는 값)
                        riter = m.rbegin(); //맵의 가장 마지막 원소 접근
                        m.erase(m.find(riter->first)); //맵의 가장 마지막 원소(최소값) 제거

                        }
                    }
 
                }
 
        }

        if(m.empty()){ //맵이 비어있는 경우
            cout << "EMPTY" << '\n';
        }
        else{ //비어있지 않는 경우 맵의 최대,최소 값 출력(최대 -> 첫번쨰 ,최소->마지막 원소)
            iter = m.begin();
            cout << iter->first << ' ';
            riter = m.rbegin();
            cout << riter->first << '\n';
        }
 
    }
 
 
}